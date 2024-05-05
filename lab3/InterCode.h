#include "Semantic.h"
typedef struct Operand_* Operand;
typedef struct InterCode_* InterCode;    
typedef enum { VARIABLE_, CONSTANT_, ADDRESS_, LABEL1, FUNCTION1, RELOP_ , DER_} op_kind;
typedef enum { ASSIGN_, ADD_, SUB_, MUL_, DIV_, GOTO_, RETURN_, LABEL_, IF_, READ_, WRITE_, CALL_, ARG_, DEC_,PARAM_,FUNCTION_ } code_kind;
struct ArgsList {
    Operand arg;
    struct ArgsList *next;
};
struct Operand_ {
    op_kind kind;
    union {
        int value;
        char name[MAX_NAME_LEN];
    } u;
};
struct InterCode_
{
    code_kind kind;
    union {
        struct { Operand right, left; } assign;
        struct { Operand result, op, op2; } binop;
        Operand goto_label;
        Operand label;
        struct { Operand t1, op, t2, label_true; } if_goto;
        Operand ret;
        Operand read;
        Operand write;
        Operand arg;
        struct { Operand result; Operand func } call;    
        struct { Operand var, size } dec;    
    } u;
    InterCode prev, next;
};
void insert_Intercode(InterCode code);
void print_Intercode();
Operand new_temp();
Operand new_label();
InterCode link_(InterCode code1, InterCode code2);
Operand create_Immediate(int value);
void translate_Program(node Program);
void translate_ExtDefList(node ExtDefList);
void translate_ExtDef(node ExtDef);
void translate_ExtDecList(node ExtDecList);
void translate_VarDec(node VarDec);
void translate_FunDec(node FunDec);
void translate_VarList(node VarList);
void translate_ParamDec(node ParamDec);
void translate_CompSt(node CompSt);
void translate_StmtList(node StmtList);
void translate_DefList(node DefList);
void translate_Def(node Def);
void translate_DecList(node DecList);
void translate_Dec(node Dec);
InterCode translate_Cond(node Exp, Operand label_true, Operand label_false);
InterCode translate_Stmt(node Stmt);
InterCode translate_Args(node Args, Operand* args, int num);
InterCode translate_Exp(node Exp, Operand place);
