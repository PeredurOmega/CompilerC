# Compiler C

This repository is a C compiler for x86 implemented at INSA Lyon.

## Authors and major contributors

* Rivaldo De Souza
* Emmanuel Garreau
* Mathis Goichon
* Bérenger Mayoud--Dupin
* Paul Souteyrat

## Build project

### Ubuntu

To build the project, go to **CompilerC** directory and use:

```bash
cmake -B build
cmake --build build --target compiler
```

### Windows

Prefer use WSL Ubuntu and run the two commands given above.

## Test framework

To run the test framework, you have to:

```bash
cd tests
python3 ifcc-test.py .
```

## About grammar generation

If you make any change in the grammar, you can generate Cpp code with the following commands:

```bash
cd compiler
java -cp ../antlr-4.10.1-complete.jar org.antlr.v4.Tool -lib ./ -visitor -listener -Dlanguage=Cpp -o ./generated ./ifcc.g4
```

## About CI/CD

We have implemented a CI/CD which build and execute the tests.

You can access our workflows through the Actions tab and then by selecting one of the jobs.

You will find a full report in the unit test result : https://github.com/PeredurOmega/CompilerC/actions/runs/2503655455

You can also download the artifact of the test output.

## Roadmap

Features to implement (**x86**):

- [X] Variable declaration
- [X] Multiple declaration (int a, b, c)
- [X] Anywhere variable declaration
- [X] Variable assignment
- [X] Multiple assignment (int a = b = c)
- [X] Variable initialisation (a = 0)
- [X] Function declaration with int and void type _(call not implemented)_
- [X] Multiple functions declaration _(call not implemented)_
- [X] Ignore comments
- [X] Supporting int type (32 bits)
- [X] Constant support
- [X] Arithmetics operations (+, -, *, /, %)
- [X] Bitwise logical operations (&, |, ^)
- [X] Comparison operator (==, !=, <, <=, >, >=)
- [X] Logical operator (&&, ||)
- [X] Unary operators (+, -, !, ~)
- [X] Shift bit operator (>>, <<)
- [X] Block structure
- [X] Conditional structure (if else)
- [X] Return support
- [X] Empty function support
- [X] Empty return support
- [X] IR migration
- [X] Conditional return support
- [X] While
- [X] Always return optimization
- [X] Do not compile on assignment in single line if-else-else if-while statements
- [ ] Break and Continue keyword
- [ ] Char support
- [ ] Statical analysis (variable scope, shadowing)
- [ ] Function call
- [ ] For
- [ ] Switch case
- [ ] Arrays
- [ ] Pointers
- [ ] Various optimisation