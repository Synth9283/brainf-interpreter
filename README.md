# brainf-interpreter
A brainf interpreter made in C with dynamic memory allocation
## Features
- Dynamic memory allocation
    - Implemented by using linked lists utilizing the heap rather than a fixed size in the stack
    - This means that the only limit is the size of your memory!
- GNU Autotools supported
    - Easy to compile and install the interpreter
- Easy to compile
    - It does not depend on any external dependencies. All you need is the standard library!
## Requirements
- C compiler
- Standard Libraries
- git
## Usage
- Hello World!
```
bf "++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>++.>+.+++++++..+++.<<++.>+++++++++++++++.>.+++.------.--------.<<+."
```
## Compiling
- With GNU Autotools
```
git clone https://github.com/Synth9283/brainf-interpreter.git
cd brainf-interpreter
mkdir build
cd build
../configure
make
```
- Without GNU Autotools
```
git clone https://github.com/Synth9283/brainf-interpreter.git
cd brainf-interpreter
gcc main.c -O3 -o bf
```
## Installation
- With GNU Autotools
```
make install
```
- Without GNU Autotools
    - You will have to add the executable into your PATH
