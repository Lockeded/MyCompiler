#!/bin/bash
flex lexical.l
bison -d syntax.y --warnings=none
gcc -g syntax.tab.c NodeUtil.c SymbolTable.c Semantic.c InterCode.c -lfl -ly -lm -o parser 
