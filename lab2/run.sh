#!/bin/bash
flex lexical.l
bison -d syntax.y --warnings=none
gcc -g syntax.tab.c NodeUtil.c SymbolTable.c Semantic.c -lfl -ly -lm -o parser 
for i in {1..17}; do
    echo "Test $i:"
    ./parser test$i
done
for i in {1..6}; do
    echo "TestOpt $i:"
    ./parser opt$i
done