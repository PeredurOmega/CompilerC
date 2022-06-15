#!/usr/bin/env python3

# This scripts runs GCC as well as IFCC on each test-case provided and compares the results.
#
# input: the test-cases are specified either as individual
#         command-line arguments, or as part of a directory tree
#
# output: 
#
# The script is divided in three distinct steps:
# - in the ARGPARSE step, we understand the command-line arguments
# - in the PREPARE step, we copy all our test-cases into a single directory tree
# - in the TEST step, we actually run GCC and IFCC on each test-case
#
#

import argparse
import glob
import os
import shutil
import sys
import subprocess


def command(string, logfile=None):
    """execute `string` as a shell command, optionnaly logging stdout+stderr to a file. return exit status.)"""
    if args.verbose:
        print("ifcc-test.py: " + string)
    try:
        output = subprocess.check_output(string, stderr=subprocess.STDOUT, shell=True)
        ret = 0
    except subprocess.CalledProcessError as e:
        ret = e.returncode
        output = e.output

    if logfile:
        f = open(logfile, 'w')
        print(output.decode(sys.stdout.encoding) + '\n' + 'return code: ' + str(ret), file=f)
        f.close()

    return ret


def dumpfile(name):
    print(open(name).read(), end='')


######################################################################################
## ARGPARSE step: make sense of our command-line arguments

argparser = argparse.ArgumentParser(
    description="Compile multiple programs with both GCC and IFCC, run them, and compare the results.",
    epilog=""
)

argparser.add_argument('input', metavar='PATH', nargs='+', help='For each path given:'
                                                                + ' if it\'s a file, use this file;'
                                                                + ' if it\'s a directory, use all *.c files in this subtree')

argparser.add_argument('-d', '--debug', action="count", default=0,
                       help='Increase quantity of debugging messages (only useful to debug the test script itself)')
argparser.add_argument('-v', '--verbose', action="count", default=0,
                       help='Increase verbosity level. You can use this option multiple times.')
argparser.add_argument('-w', '--wrapper', metavar='PATH',
                       help='Invoke your compiler through the shell script at PATH. (default: `ifcc-wrapper.sh`)')

args = argparser.parse_args()

if args.debug >= 2:
    print('debug: command-line arguments ' + str(args))

orig_cwd = os.getcwd()
if "ifcc-test-output" in orig_cwd:
    print('error: cannot run from within the output directory')
    exit(1)

if os.path.isdir('ifcc-test-output'):
    # cleanup previous output directory
    command('rm -rf ifcc-test-output')
os.mkdir('ifcc-test-output')

## Then we process the inputs arguments i.e. filenames or subtrees
inputfilenames = []
for path in args.input:
    path = os.path.normpath(path)  # collapse redundant slashes etc.
    if os.path.isfile(path):
        if path[-2:] == '.c':
            inputfilenames.append(path)
        else:
            print("error: incorrect filename suffix (should be '.c'): " + path)
            exit(1)
    elif os.path.isdir(path):
        for dirpath, dirnames, filenames in os.walk(path):
            inputfilenames += [dirpath + '/' + name for name in filenames if name[-2:] == '.c']
    else:
        print("error: cannot read input path `" + path + "'")
        sys.exit(1)

## debug: after treewalk
if args.debug:
    print("debug: list of files after tree walk:", " ".join(inputfilenames))

## sanity check
if len(inputfilenames) == 0:
    print("error: found no test-case in: " + " ".join(args.input))
    sys.exit(1)

## Here we check that  we can actually read the files.  Our goal is to
## fail as early as possible when the CLI arguments are wrong.
for inputfilename in inputfilenames:
    try:
        f = open(inputfilename, "r")
        f.close()
    except Exception as e:
        print("error: " + e.args[1] + ": " + inputfilename)
        sys.exit(1)

## Last but not least: we now locate the "wrapper script" that we will
## use to invoke ifcc
if args.wrapper:
    wrapper = os.path.realpath(os.getcwd() + "/" + args.wrapper)
else:
    wrapper = os.path.dirname(os.path.realpath(__file__)) + "/ifcc-wrapper.sh"

if not os.path.isfile(wrapper):
    print("error: cannot find " + os.path.basename(wrapper) + " in directory: " + os.path.dirname(wrapper))
    exit(1)

if args.debug:
    print("debug: wrapper path: " + wrapper)

######################################################################################
## PREPARE step: copy all test-cases under ifcc-test-output

jobs = []

for inputfilename in inputfilenames:
    if args.debug >= 2:
        print("debug: PREPARING " + inputfilename)

    if 'ifcc-test-output' in os.path.realpath(inputfilename):
        print('error: input filename is within output directory: ' + inputfilename)
        exit(1)

    ## each test-case gets copied and processed in its own subdirectory:
    ## ../somedir/subdir/file.c becomes ./ifcc-test-output/somedir-subdir-file/input.c
    subdir = 'ifcc-test-output/' + inputfilename.strip("./")[:-2].replace('/', '-')
    os.mkdir(subdir)
    shutil.copyfile(inputfilename, subdir + '/input.c')
    jobs.append(subdir)

## eliminate duplicate paths from the 'jobs' list
unique_jobs = []
for j in jobs:
    for d in unique_jobs:
        if os.path.samefile(j, d):
            break  # and skip the 'else' branch
    else:
        unique_jobs.append(j)
jobs = sorted(unique_jobs)
# debug: after deduplication
if args.debug:
    print("debug: list of test-cases after deduplication:", " ".join(jobs))

######################################################################################
## TEST step: actually compile all test-cases with both compilers

endl = "\n"
tab = "    "

xml_result = "<testsuites tests=\"" + str(len(jobs)) + "\">" + endl

currentDir = ""
directory_cpt = 0
directory_size = 0

for jobname in jobs:
    os.chdir(orig_cwd)

    test_name = jobname.split('/')[1]
    test_name = test_name.replace('tests-', '')

    if currentDir != test_name.split('-')[1]:
        currentDir = test_name.split('-')[1]
        list_files = os.listdir("testfiles/" + currentDir)
        directory_cpt = 0
        directory_size = len(list_files)
        xml_result += tab + "<testsuite tests=\"" + str(directory_size) + "\">" + endl
        print("TEST-SUITE: " + currentDir)
    directory_cpt += 1

    xml_result += tab + tab + "<testcase classname=\"" + currentDir + "\" name=\"" + test_name.split('-')[2] + "\""
    print(tab + 'TEST-CASE: ' + currentDir + "/" + test_name.split('-')[2])
    os.chdir(jobname)

    ## Reference compiler = GCC
    gccstatus = command("gcc -S -o asm-gcc.s input.c", "gcc-compile.txt")
    if gccstatus == 0:
        # test-case is a valid program. we should run it
        gccstatus = command("gcc -o exe-gcc asm-gcc.s", "gcc-link.txt")
    if gccstatus == 0:  # then both compile and link stage went well
        exegccstatus = command("./exe-gcc", "gcc-execute.txt")
        if args.verbose >= 2:
            dumpfile("gcc-execute.txt")

    ## IFCC compiler
    ifccstatus = command(wrapper + " asm-ifcc.s input.c", "ifcc-compile.txt")

    if gccstatus != 0 and ifccstatus != 0:
        ## ifcc correctly rejects invalid program -> test-case ok
        xml_result += "/>" + endl
        if directory_cpt == directory_size:
            xml_result += tab + "</testsuite>" + endl
        print(tab + "TEST OK")
        continue
    elif gccstatus != 0 and ifccstatus == 0:
        ## ifcc wrongly accepts invalid program -> error
        xml_result += ">" + endl
        xml_result += tab + tab + tab + "<failure type=\"AcceptInvalidProgram\">Your compiler accepts an invalid program</failure>" + endl
        xml_result += tab + tab + "</testcase>" + endl
        if directory_cpt == directory_size:
            xml_result += tab + "</testsuite>" + endl
        print(tab + "TEST FAIL (your compiler accepts an invalid program)")
        continue
    elif gccstatus == 0 and ifccstatus != 0:
        ## ifcc wrongly rejects valid program -> error
        xml_result += ">" + endl
        xml_result += tab + tab + tab + "<failure type=\"RejectsValidProgram\">Your compiler rejects a valid program</failure>" + endl
        xml_result += tab + tab + "</testcase>" + endl
        if directory_cpt == directory_size:
            xml_result += tab + "</testsuite>" + endl
        print(tab + "TEST FAIL (your compiler rejects a valid program)")
        if args.verbose:
            dumpfile("ifcc-compile.txt")
        continue
    else:
        ## ifcc accepts to compile valid program -> let's link it
        ldstatus = command("gcc -o exe-ifcc asm-ifcc.s", "ifcc-link.txt")
        if ldstatus:
            xml_result += ">" + endl
            xml_result += tab + tab + tab + "<failure type=\"IncorrectAssembly\">Your compiler produces incorrect assembly</failure>" + endl
            xml_result += tab + tab + "</testcase>" + endl
            if directory_cpt == directory_size:
                xml_result += tab + "</testsuite>" + endl
            print(tab + "TEST FAIL (your compiler produces incorrect assembly)")
            if args.verbose:
                dumpfile("ifcc-link.txt")
            continue

    ## both compilers  did produce an  executable, so now we  run both
    ## these executables and compare the results.

    command("./exe-ifcc", "ifcc-execute.txt")
    if open("gcc-execute.txt").read() != open("ifcc-execute.txt").read():
        xml_result += ">" + endl
        xml_result += tab + tab + tab + "<failure type=\"WrongResult\">Different results at execution</failure>" + endl
        xml_result += tab + tab + "</testcase>" + endl
        if directory_cpt == directory_size:
            xml_result += tab + "</testsuite>" + endl
        print(tab + "TEST FAIL (different results at execution)")
        if args.verbose:
            print("GCC:")
            dumpfile("gcc-execute.txt")
            print("you:")
            dumpfile("ifcc-execute.txt")
        continue

    ## last but not least
    xml_result += "/>" + endl
    print(tab + "TEST OK")

    if directory_cpt == directory_size:
        xml_result += tab + "</testsuite>" + endl

xml_result += "</testsuites>" + endl

with open('../test_report.xml', 'w+') as file:
    file.write(xml_result)
