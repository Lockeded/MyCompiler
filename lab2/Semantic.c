#include "Semantic.h"
extern int top;
extern FieldList HeadField;
void Program(node root){
    //Program -> ExtDefList
    initHeadField();
    ExtDefList(root->child[0]);
    checkFunction();
}
void checkFunction()
{
    FieldList p = HeadField->tail;
    while (p)
    {
        if(p->isFunctionImplemented != -1){
            printf("Error type 18 at Line %d: Undefined function \"%s\".\n", p->isFunctionImplemented, (char*)p->name);
        }
        p = p->tail;
    }
}
void ExtDefList(node root){
    //ExtDefList -> ExtDef ExtDefList
    //ExtDefList -> empty

    if(root->child_num == 2){
        ExtDef(root->child[0]);
        ExtDefList(root->child[1]);
    }
}
void ExtDef(node root){
    //ExtDef -> Specifier ExtDecList SEMI
    //ExtDef -> Specifier SEMI
    //ExtDef -> Specifier FunDec CompSt
    //ExtDef -> Specifier FunDec SEMI

    Type type = Specifier(root->child[0]);
    if(!strcmp(root->child[1]->name, "ExtDecList") && type->kind != STRUCTURE){
        ExtDecList(root->child[1], type);
    }
    else if(!strcmp(root->child[1]->name, "ExtDecList") && type->kind == STRUCTURE){
        ExtDecListForStruct(root->child[1], type);
    }
    else if(!strcmp(root->child[1]->name, "FunDec") && !strcmp(root->child[2]->name, "CompSt")){
        FunDec(root->child[1], type);
        CompSt(root->child[2], type);
    }
    else if(!strcmp(root->child[1]->name, "FunDec") && !strcmp(root->child[2]->name, "SEMI")){
        FieldList field = FunDecForDec(root->child[1], type);
    }
}
Type Specifier(node root){
    //Specifier -> TYPE
    //Specifier -> StructSpecifier

    if(!strcmp(root->child[0]->name, "TYPE")){
        Type type = (Type)malloc(sizeof(struct Type_));
        type->kind = BASIC;
        if(!strcmp(root->child[0]->literal,"int")){
            type->u.basic = TYPE_INT;
        }
        else if(!strcmp(root->child[0]->literal,"float")){
            type->u.basic = TYPE_FLOAT;
        }
        return type;
    }
    else{
        return StructSpecifier(root->child[0]);
    }
}
void ExtDecListForStruct(node root, Type type){
    //ExtDecList -> VarDec
    //ExtDecList -> VarDec COMMA ExtDecList

    VarDecForStruct(root->child[0], type);
    if(root->child_num == 3){
        ExtDecListForStruct(root->child[2], type);
    }
}
void ExtDecList(node root, Type type){
    //ExtDecList -> VarDec
    //ExtDecList -> VarDec COMMA ExtDecList

    type->u.structure->Args = VarDec(root->child[0], type);
    if(root->child_num == 3){
        ExtDecList(root->child[2], type);
    }
}
FieldList VarDec(node root, Type type){
    //VarDec -> ID
    //VarDec -> VarDec LB INT RB
    if(root->child_num == 1){
        FieldList field = createField(root->child[0]->literal, type);
        if(searchField(root->child[0]->literal)){
            printf("Error type 3 at Line %d: Redefined variable \"%s\".\n", root->child[0]->line, (char*)root->child[0]->literal);
            freeField(field);
        }
        else{
            insertField(field);
            return field;
        }
    }
    else{
        Type array_type = (Type)malloc(sizeof(struct Type_));
        array_type->kind = ARRAY;
        array_type->u.array.elem = type;
        array_type->u.array.size = *((int*)root->child[2]->literal);
        return VarDec(root->child[0], array_type);
    }
    
}
FieldList VarDecForStruct(node root, Type type){
    //VarDec -> ID
    //VarDec -> VarDec LB INT RB
    if(root->child_num == 1){
        FieldList field = createField(root->child[0]->literal, type);
        if(searchField(root->child[0]->literal)){
            printf("Error type 15 at Line %d: Redefined field \"%s\".\n", root->child[0]->line, (char*)root->child[0]->literal);
            freeField(field);
        }
        else{
            insertField(field);
            return field;
        }
    }
    else{
        Type array_type = (Type)malloc(sizeof(struct Type_));
        array_type->kind = ARRAY;
        array_type->u.array.elem = type;
        array_type->u.array.size = *((int*)root->child[2]->literal);
        return VarDecForStruct(root->child[0], array_type);
    }
    
}
FieldList FunDec(node root, Type type){
    //FunDec -> ID LP VarList RP
    //FunDec -> ID LP RP
    type->kind = FUNCTION;
    FieldList field = searchField(root->child[0]->literal);
    if(field && field->isFunctionImplemented == -1){
        printf("Error type 4 at Line %d: Redefined function \"%s\".\n", root->child[0]->line, (char*)root->child[0]->literal);
        return NULL;
    }
    if(!field){
        FieldList new_field = createField(root->child[0]->literal, type);
        new_field->argc = 0;
        if(root->child_num == 4){
            new_field->Args = VarList(root->child[2],&field->argc);
        }
        insertField(new_field);
        return new_field;
    }
    else{
        field->isFunctionImplemented = -1;
        return field;
    }
}
FieldList FunDecForDec(node root, Type type){
    //FunDec -> ID LP VarList RP
    //FunDec -> ID LP RP
    type->kind = FUNCTION;
    FieldList field = searchField(root->child[0]->literal);
    if(field && field->isFunctionImplemented == -1){
        printf("Error type 4 at Line %d: Redefined function \"%s\".\n", root->child[0]->line, (char*)root->child[0]->literal);
        return NULL;
    }
    node p = root->child[2];
    FieldList new_field = createField(root->child[0]->literal, type);
    new_field->isFunctionImplemented = root->child[0]->line;
    new_field->argc = 0;
    if(root->child_num == 4){
        new_field->Args = VarList(root->child[2],&field->argc);
    }
    if(field && field->isFunctionImplemented != -1 && (field->argc != new_field->argc || memcmp(&field->type->u, &type->u, sizeof(type->u)) != 0 || memcmp(&field->Args->type->u, &new_field->Args->type->u, sizeof(type->u)) != 0)){
        printf("Error type 19 at Line %d: Inconsistent declaration of function \"%s\".\n", root->child[0]->line, (char*)root->child[0]->literal);
        return NULL;
    }
    insertField(new_field);
    return new_field;
}
FieldList VarList(node root,int* argc){
    //VarList -> ParamDec
    //VarList -> ParamDec COMMA VarList
    FieldList field = ParamDec(root->child[0]);
    *argc++;
    if(root->child_num == 3){
        field->tail = VarList(root->child[2],argc);
    }
    return field;
}
FieldList ParamDec(node root){
    //ParamDec -> Specifier VarDec
    Type type = Specifier(root->child[0]);
    return VarDec(root->child[1], type);
}   
Type StructSpecifier(node root){
    //StructSpecifier -> STRUCT OptTag LC DefList RC
    //StructSpecifier -> STRUCT Tag

    Type type = (Type)malloc(sizeof(struct Type_));
    type->kind = STRUCTURE;
    type->u.structure = NULL;
    if(!strcmp(root->child[1]->name, "OptTag")){
        OptTag(root->child[1],type);
        DefListForStruct(root->child[3]);
    }
    else{
        Tag(root->child[1],type);   
    }
    return type;
}
void OptTag(node root, Type type){
    if(searchField(root->child[0]->literal)){
        printf("Error type 16 at Line %d:  Duplicated name \"%s\".\n", root->child[0]->line, (char*)root->child[0]->literal);
    }
    else{
        FieldList field = createField(root->child[0]->literal, type);
        type->u.structure = field;
        insertField(field);
    }
}
void Tag(node root,Type type){
    //Tag -> ID
    if(!searchField(root->child[0]->literal)){
        printf("Error type 17 at Line %d:  Undefined structure \"%s\".\n", root->child[0]->line, (char*)root->child[0]->literal);
    }
    else{
        FieldList field = createField(root->child[0]->literal, type);
        type->u.structure = field;
        insertField(field);
    }
}
void CompSt(node root, Type type){
    //CompSt -> LC DefList StmtList RC
    if (root->child_num < 4)
    {
        return;
    }
    DefList(root->child[1]);
    StmtList(root->child[2], type);
}
void DefListForStruct(node root){
    //DefList -> Def DefList
    //DefList -> empty
    if(!root){
        return;
    }
    if(root->child_num == 2){
        DefForStruct(root->child[0]);
        DefListForStruct(root->child[1]);
    }
}
void DefForStruct(node root){
    //Def -> Specifier DecList SEMI
    Type type = Specifier(root->child[0]);
    DecListForStruct(root->child[1], type);
}
void DecListForStruct(node root, Type type){
    //DecList -> Dec
    //DecList -> Dec COMMA DecList
    DecForStruct(root->child[0], type);
    if(root->child_num == 3){
        DecListForStruct(root->child[2], type);
    }
}
void DecForStruct(node root, Type type){
    //Dec -> VarDec
    //Dec -> VarDec ASSIGNOP Exp
    VarDecForStruct(root->child[0], type);
    if(root->child_num == 3){
        printf("Error type 15 at Line %d: Defined field in initializing \"%s\".\n", root->child[0]->line, (char*)root->child[0]->literal);
    }
}
void DefList(node root){
    //DefList -> Def DefList
    //DefList -> empty
    if(!root){
        return;
    }
    if(root->child_num == 2){
        Def(root->child[0]);
        DefList(root->child[1]);
    }
}
void Def(node root){
    //Def -> Specifier DecList SEMI

    Type type = Specifier(root->child[0]);
    DecList(root->child[1], type);
}
void DecList(node root, Type type){
    //DecList -> Dec
    //DecList -> Dec COMMA DecList

    Dec(root->child[0], type);
    if(root->child_num == 3){
        DecList(root->child[2], type);
    }
}
void Dec(node root, Type type){
    //Dec -> VarDec
    //Dec -> VarDec ASSIGNOP Exp

    VarDec(root->child[0],type);
    if(root->child_num == 3){
        Exp(root->child[2]);
    }
}
void StmtList(node root, Type type){
    //StmtList -> Stmt StmtList
    //StmtList -> empty
    if (!root)      
    {
        return;
    }
    
    if(root->child_num == 2){
        Stmt(root->child[0], type);
        StmtList(root->child[1], type);
    }
}
void Stmt(node root, Type type){
    //Stmt -> Exp SEMI
    //Stmt -> CompSt
    //Stmt -> RETURN Exp SEMI
    //Stmt -> IF LP Exp RP Stmt
    //Stmt -> IF LP Exp RP Stmt ELSE Stmt
    //Stmt -> WHILE LP Exp RP Stmt

    if(!strcmp(root->child[0]->name, "Exp")){
        Exp(root->child[0]);
    }
    else if(!strcmp(root->child[0]->name, "CompSt")){
        CompSt(root->child[0], type);
    }
    else if(!strcmp(root->child[0]->name, "RETURN")){
        Type return_type = Exp(root->child[1]);
        if(memcmp(&return_type->u, &type->u, sizeof(type->u)) != 0){
            printf("Error type 8 at Line %d: Type mismatched for return.\n", root->child[0]->line);
        }
    }
    else if(!strcmp(root->child[0]->name, "IF")){
        Exp(root->child[2]);
        Stmt(root->child[4], type);
        if(root->child_num == 7){
            Stmt(root->child[6], type);
        }
    }
    else if(!strcmp(root->child[0]->name, "WHILE")){
        Exp(root->child[2]);
        Stmt(root->child[4], type);
    }
}
Type Exp(node root){
    //Exp -> Exp ASSIGNOP Exp
    //Exp -> Exp AND Exp
    //Exp -> Exp OR Exp
    //Exp -> Exp RELOP Exp
    //Exp -> Exp PLUS Exp
    //Exp -> Exp MINUS Exp
    //Exp -> Exp STAR Exp
    //Exp -> Exp DIV Exp
    //Exp -> LP Exp RP
    //Exp -> MINUS Exp
    //Exp -> NOT Exp
    //Exp -> ID LP Args RP
    //Exp -> ID LP RP
    //Exp -> Exp LB Exp RB
    //Exp -> Exp DOT ID
    //Exp -> ID
    //Exp -> INT
    //Exp -> FLOAT
    if(root->child_num == 1){
        if((root->child[0]->literal_type==TYPE_ID)){
            FieldList field = searchField(root->child[0]->literal);
            if(!field){
                printf("Error type 1 at Line %d: Undefined variable \"%s\".\n", root->child[0]->line, (char*)root->child[0]->literal);
            }
            else{
                return field->type;
            }
        }
        else if((root->child[0]->literal_type==TYPE_INT)){
            Type type = (Type)malloc(sizeof(struct Type_));
            type->kind = BASIC;
            type->u.basic = TYPE_INT;
            return type;
        }
        else if((root->child[0]->literal_type==TYPE_FLOAT)){
            Type type = (Type)malloc(sizeof(struct Type_));
            type->kind = BASIC;
            type->u.basic = TYPE_FLOAT;
            return type;
        }
    }
    else if (root->child_num == 2){
        if(!strcmp(root->child[0]->name, "MINUS") || !strcmp(root->child[0]->name, "NOT")){
                return Exp(root->child[1]);
            }
    }
    else if(!strcmp(root->child[1]->name, "ASSIGNOP")){
        Type type_1 = Exp(root->child[0]);
        Type type_2 = Exp(root->child[2]);
        if(!type_1 || !type_2){
            return NULL;
        }
        node p = root->child[0];
        while(p->child_num != 1){
            p = p->child[0];
        }
        if(p->child[0]->literal_type != TYPE_ID){
             printf("Error type 6 at Line %d: The left-hand side of an assignment must be a variable.\n", p->child[0]->line);
        }
        else if(type_1->kind == STRUCTURE || type_2->kind == STRUCTURE){
            if(memcmp(&type_1->u,&type_2->u,sizeof(type_1->u)) != 0){
                printf("Error type 5 at Line %d: Type mismatched for assignment.\n", root->child[1]->line);
            }
            // FieldList p = type_1->u.structure->Args;
            // FieldList q = type_2->u.structure->Args;
            // while(p && q){
            //     printf("%d%d",p->type->u.basic,q->type->u.basic);
            //     if(memcmp(&p->type->u,&q->type->u,sizeof(p->type->u)) != 0){
            //         printf("Error type 5 at Line %d: Type mismatched for assignment.\n", root->child[1]->line);
            //         break;
            //     }
            //     p = p->tail;
            //     q = q->tail;
            // }
        }
        else if(memcmp(&type_1->u, &type_2->u, sizeof(type_1->u)) != 0){
            printf("Error type 5 at Line %d: Type mismatched for assignment.\n", root->child[1]->line);
        }

    }
    else if(!strcmp(root->child[1]->name, "AND") || !strcmp(root->child[1]->name, "OR") || !strcmp(root->child[1]->name, "RELOP") || !strcmp(root->child[1]->name, "PLUS") || !strcmp(root->child[1]->name, "MINUS") || !strcmp(root->child[1]->name, "STAR") || !strcmp(root->child[1]->name, "DIV")){
        Type type_1 = Exp(root->child[0]);
        Type type_2 = Exp(root->child[2]);
        if(!type_1 || !type_2){
            return NULL;
        }
        if(memcmp(&type_1->u, &type_2->u, sizeof(type_1->u)) != 0){
            printf("Error type 7 at Line %d: Type mismatched for operands.\n", root->child[1]->line);
        }
    }
    else if(!strcmp(root->child[1]->name, "LB")){
        Type type_1 = Exp(root->child[0]);
        Type type_2 = Exp(root->child[2]);
        if(!type_1 || !type_2){
            return NULL;
        }
        if(type_1->kind != ARRAY){
            printf("Error type 10 at Line %d: \"%s\" is not an array.\n",
                    root->child[0]->line, (char*)root->child[0]->child[0]->literal);
        }
        if(type_2->u.basic != TYPE_INT || type_2->kind != BASIC){
            if(type_2->u.basic == TYPE_FLOAT){
                printf("Error type 12 at Line %d: \"%g\" is not an integer.\n",
                    root->child[2]->line, *((float*)root->child[2]->child[0]->literal));
            }
            else{
                printf("Error type 12 at Line %d: \"%s\" is not an integer.\n",
                    root->child[2]->line, (char*)root->child[2]->child[0]->literal);
            }
        }
        return type_1->u.array.elem;
    }
    else if(!strcmp(root->child[1]->name, "DOT")){
        Type type_1 = Exp(root->child[0]);
        Type type_2 = NULL;
        FieldList field = searchField(root->child[2]->literal);
        if(!field){
                printf("Error type 14 at Line %d: Non-existent field \"%s\".\n", root->child[2]->line, (char*)root->child[2]->literal);
            }
            else{
                type_2 = field->type;
            }
        if(!type_1 || !type_2){
            return NULL;
        }
        if(type_1->kind != STRUCTURE){
            printf("Error type 13 at Line %d: Illegal use of \".\"\n",
                    root->child[2]->line);
                    return NULL;
        }
        return type_2;
    }
    else if(!strcmp(root->child[1]->name, "LP")){
        FieldList field = searchField(root->child[0]->literal);
        if(!field){
                printf("Error type 2 at Line %d: Undefined function \"%s\".\n", root->child[0]->line, (char*)root->child[0]->literal);
            }
        else if(field->type->kind != FUNCTION){
                printf("Error type 11 at Line %d: \"%s\" is not a function.\n", root->child[0]->line, (char*)root->child[0]->literal);
            }
        else if(!strcmp(root->child[2]->name, "Args")){
            Args(root,field->argc);
        }
        else{
                return field->type;
            }
    }
}
void Args(node root,int argc){
    //Args -> Exp
    //Args -> Exp COMMA Args
    int count = 1;
    node p = root->child[2];
    while (p->child[2])
    {
        p = p->child[2];
        Exp(p->child[0]);
        count++;
    }
    if(count != argc){
        printf("Error type 9 at Line %d: The number of arguments is different from the function definition.\n", root->child[0]->line);
    }
    Exp(p->child[0]);
}
void semantic(node root){
    Program(root);
    //printTable(root);
}