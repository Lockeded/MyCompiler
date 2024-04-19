#!/bin/bash
flex lexical.l
bison -d syntax.y
gcc syntax.tab.c NodeUtil.c -lfl -ly -lm -o parser