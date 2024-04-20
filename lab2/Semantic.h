#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "SymbolTable.h"

void Program(node root);
void ExtDefList(node root);
void ExtDef(node root);
Type Specifier(node root);
void ExtDecList(node root, Type type);
FieldList VarDec(node root, Type type);
FieldList FunDec(node root, Type type);
FieldList VarList(node root,int* argc);
FieldList ParamDec(node root);
Type StructSpecifier(node root);
void Tag(node root, Type type);
void OptTag(node root, Type type);
void CompSt(node root, Type type);
void DefList(node root);
void Def(node root);
void DecList(node root, Type type);
void Dec(node root, Type type);
void StmtList(node root, Type type);
void Stmt(node root, Type type);
Type Exp(node root);
void semantic(node root);
void Args(node root,int argc);

#endif /* SEMANTIC_H */