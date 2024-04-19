#include "SymbolTable.h"
FieldList HeadField = NULL;
FieldList FieldStack[MAX_STACK_LEN];
int top = 0;
void insertField(FieldList newfield){
    newfield->tail = HeadField->tail;
    HeadField->tail = newfield;
}

int isExist(FieldList field){
    FieldList p = HeadField->tail;
    while (p != NULL){
        if(!strcmp(p->name, field->name)){
            return 1;   //表中存在符号=True
        }
    }
    return 0;
}

void initHeadField(){
    HeadField = (FieldList)malloc(sizeof(struct FieldList_));
}

void pushStack(FieldList f){
    top++;
    FieldStack[top] = f;
}

FieldList popStack(){
    FieldList f = FieldStack[top];
    top--;
    return f;
}

FieldList SearchStack(char* name){
    for(int i = top; i>=0; i--){
        FieldList f = FieldStack[i];
        if(!strcmp(name,f->name)){
            return f;
        }
    }
    return NULL;
}

FieldList createField(char* name, Type type){
    FieldList field = (FieldList)malloc(sizeof(struct FieldList_));
    field->name = (char*)malloc(MAX_NAME_LEN * sizeof(char));
    strcpy(field->name, name);
    field->type = type;
    field->tail = NULL;
    field->isFunctionImplemented = 0;
    return field;
}

// Type createType(Kind kind, )
void freeField(FieldList field){
    free(field->name);
    while (field->tail)
    {
        freeField(field->tail);
    }
    free(field);
}

FieldList searchField(char* name){
    FieldList p = HeadField->tail;
    while(p){
        if(!strcmp(name, p->name)){
            return p;
        }
        p = p->tail;
    }
    return NULL;
}

void printTable(){
    // printf("in printTable\n");
    FieldList p = HeadField->tail;
    while (p)
    {
        printf("symbol: %s\n", p->name);
        p = p->tail;
    }
}

// int main(){
//     initHeadField();
//     char* name = "nihao";
//     FieldList new = createField(name,NULL);
//     insertField(new);
//     printf("%d\n",isExist(new));
//     printTable();
// }