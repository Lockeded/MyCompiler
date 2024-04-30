typedef struct Operand_* Operand;
int var_no = 0;
int label_no = 0;
typedef enum { VARIABLE, CONSTANT, ADDRESS, LABEL, FUNCTION, RELOP } op_kind
typedef enum { ASSIGN, ADD, SUB, MUL, DIV, GOTO, RETURN, LABEL, IF, READ, WRITE, CALL, ARG, DEC } code_kind;
struct ArgsList {
    Operand arg;
    struct ArgsList *next;
};
struct Operand_ {
    op_kind kind;
    union {
        int var_no;
        int value;
        char name[MAX_NAME_LEN];
    } u;
};
struct InterCode
{
    code_kind kind;
    union {
        struct { Operand right, left; } assign;
        struct { Operand result, op, op2; } binop;
        Operand goto_label;
        struct { Operand t1, op, t2, label_true } if_goto;
        Operand read;
        Operand write;
        Operand arg;
        struct { Operand result, func_name } call;    
        Operand dec_name;    
    } u;
}
struct InterCodes { InterCode code; struct InterCodes *prev, *next; };
struct InterCodes *head = NULL, *tail = NULL;
