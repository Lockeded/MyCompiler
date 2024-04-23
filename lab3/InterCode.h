typedef struct Operand_* Operand;
struct Operand_ {
    enum { VARIABLE, CONSTANT, ADDRESS } kind;
    union {
        int var_no;
        int value;
    } u;
};

struct InterCode
{
    enum { ASSIGN, ADD, SUB, MUL } kind;
    union {
        struct { Operand right, left; } assign;
        struct { Operand result, op, op2; } binop;
    } u;
}
struct InterCodes { InterCode code; struct InterCodes *prev, *next; };