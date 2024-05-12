#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include "Node.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_NAME_LEN 500
#define MAX_STACK_LEN 100
typedef struct Type_* Type;
typedef struct FieldList_* FieldList;
typedef enum {BASIC,ARRAY,STRUCTURE,FUNCTION} Kind;

struct Type_
{
    Kind kind;
    int isID;
    union{
        ValueType basic;
        struct {Type elem; int size;} array;
        FieldList structure;
    }u; 
};
struct FieldList_
{
    char* name;
    Type type;
    FieldList tail;
    FieldList Args;
    int isFunctionImplemented;
    int argc;
};

void insertField(FieldList newfield);
int isExist(FieldList field);
void initHeadField();
void pushStack(FieldList f);
FieldList popStack();
FieldList SearchStack(char* name);
FieldList createField(char* name, Type type);
void freeField(FieldList field);
FieldList searchField(char* name);
void printTable();

#endif