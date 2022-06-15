# Compiler C

This repository contains a project of C compiler for PLD Compilateur lesson at INSA Lyon.

## Authors and major contributors

* Rivaldo De Souza
* Emmanuel Garreau
* Mathis Goichon
* Bérenger Mayoud--Dupin
* Paul Souteyrat

## Build project

### Ubuntu

To build the project, go in **CompilerC** directory and use :

* `cmake -B build`
* `cmake --build build --target compiler`

### Windows

Prefer use WSL Ubuntu and run the two commands given above.

## Test framework

To run the test framework, you have to :
* `cd tests`
* `python3 ifcc-test.py .`

## About grammar generation

* `cd compiler`
* `java -cp ../antlr-4.9.2-complete.jar org.antlr.v4.Tool -lib ./ -visitor -listener -Dlanguage=Cpp -o ./generated ./ifcc.g4`
