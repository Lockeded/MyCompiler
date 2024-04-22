#!/bin/bash
flex lexical.l
bison -d syntax.y
gcc -g syntax.tab.c NodeUtil.c SymbolTable.c Semantic.c -lfl -ly -lm -o parser 
# for i in {1..17}; do
#     ./parser test$i
# done

# ./parser opt1
# ./parser opt2