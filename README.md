# Compilers

Compilers are software systems that translate programming languages into instructions that can be executed by a computer.

## Compilers steps

### Lexical Analysis

Scanning, lexing or lexical analysis takes in the linear stream of characters and chunks them into tokens.

### Parsing

This is where our syntax gets a grammar, it takes the tokens and buils a tree, the _Abstract Syntax Tree_, that mirrors the nested nature of the grammar.

### Static Analysis

This is where we check variable types, scopes, etc...

## Compilers and Interpreters

A compiler translates source code to byte code and doesn't execute it. A interpreter translates the source code and execute it immediately.

Lua lexical analysis: https://github.com/lua/lua/blob/master/llex.c
