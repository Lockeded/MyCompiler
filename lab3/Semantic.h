#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "SymbolTable.h"

void Program(node root);
void checkFunction();
void ExtDefList(node root);
void ExtDef(node root);
Type Specifier(node root);
void ExtDecList(node root, Type type);
void ExtDecListForStruct(node root, Type type);
FieldList VarDecForStruct(node root, Type type);
FieldList VarDec(node root, Type type);
FieldList FunDec(node root, Type type);
FieldList VarList(node root,FieldList father);
FieldList ParamDec(node root);
FieldList FunDecForDec(node root, Type type);
Type StructSpecifier(node root);
int check_args(FieldList field1, FieldList field2);
void Tag(node root, Type type);
void OptTag(node root, Type type);
void CompSt(node root, Type type);
void DefList(node root);
void DefListForStruct(node root);
void Def(node root);
void DefForStruct(node root);
void DecList(node root, Type type);
void DecListForStruct(node root, Type type);
void Dec(node root, Type type);
void DecForStruct(node root, Type type);
void StmtList(node root, Type type);
void Stmt(node root, Type type);
Type Exp(node root);
void semantic(node root);
void Args(node root,int argc);

#endif /* SEMANTIC_H */