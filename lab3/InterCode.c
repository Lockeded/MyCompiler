#include "InterCode.h"
#include "semantic.h"
extern int temp_no;
extern int label_no;
void print_Intercode(InterCode code){
    
    InterCode p = code->code;
    while(p){
        p = p->next;
        switch (p.kind)
        {
        case ASSIGN:
            printf("t%d := t%d\n", p.u.assign.left->u.var_no, p.u.assign.right->u.var_no);
            break;
        case ADD:
            printf("t%d := t%d + t%d\n", p.u.binop.result->u.var_no, p.u.binop.op->u.var_no, p.u.binop.op2->u.var_no);
            break;
        case SUB:
            printf("t%d := t%d - t%d\n", p.u.binop.result->u.var_no, p.u.binop.op->u.var_no, p.u.binop.op2->u.var_no);
            break;
        case MUL:
            printf("t%d := t%d * t%d\n", p.u.binop.result->u.var_no, p.u.binop.op->u.var_no, p.u.binop.op2->u.var_no);
            break;
        case GOTO:
            printf("GOTO label%d\n", p.u.goto_label->u.var_no);
            break;
        case RETURN:
            printf("RETURN t%d\n", p.u.return_value->u.var_no);
            break;
        case LABEL:
            printf("LABEL label%d :\n", p.u.label->u.var_no);
            break;
        default:
            break;
        }
    }
}
Operand new_temp(){
    Operand temp = (Operand)malloc(sizeof(struct Operand_));
    temp->kind = VARIABLE;
    temp->u.var_no = temp_no++;
    return temp;
}
Operand new_label(){
    Operand label = (Operand)malloc(sizeof(struct Oprand_));
    label->kind = LABEL;
    // label->u.var_no = label_no++;
    return label;
}
InterCode link(InterCode code1, InterCode code2){
    if(code1 == NULL){
        return code2;
    }
    if(code2 == NULL){
        return code1;
    }
    InterCode p = code1;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = code2;
    code2->prev = p;
    return code1;
}
Operand create_Immediate(int value){
    Operand imm = (Operand)malloc(sizeof(struct Operand_));
    imm->kind = CONSTANT;
    imm->u.value = value;
    return imm;
}
InterCode translate_Program(node Program){
    //Program -> ExtDefList
    InterCode code = malloc(sizeof(struct InterCodes));
    code->prev = NULL;
    code->next = NULL;
    code->code = translate_ExtDefList(Program->child[0]);
    return code;
}
InterCode translate_ExtDefList(node ExtDefList){
    //ExtDefList -> ExtDef ExtDefList
    //ExtDefList -> NULL
    if(ExtDefList->child_num == 0){
        return NULL;
    }
    InterCode code1 = translate_ExtDef(ExtDefList->child[0]);
    InterCode code2 = translate_ExtDefList(ExtDefList->child[1]);
    return link(code1, code2);
}
InterCode translate_ExtDef(node ExtDef){
    //ExtDef -> Specifier ExtDecList SEMI
    //ExtDef -> Specifier FunDec CompSt
    //ExtDef -> Specifier FunDec SEMI
    if(!strcmp(ExtDef->child[1]->name, "ExtDecList")){
        return NULL;
    }
    else{
        InterCode code1 = translate_FunDec(ExtDef->child[1]);
        InterCode code2 = translate_CompSt(ExtDef->child[2]);
        return link(code1, code2);
    }
}
InterCode translate_FunDec(node FunDec){
    //FunDec -> ID LP VarList RP
    //FunDec -> ID LP RP
    FieldList field = searchField(FunDec->child[0]->literal);
    Operand func = malloc(sizeof(struct Operand_));
    func->kind = FUNCTION;
    func->u.var_no = field->var_no;
    if(FunDec->child_num == 4){
        InterCode code = translate_VarList(FunDec->child[2]);
        return link(func, code);
    }
    else{
        return code;
    }
}
InterCode translate_VarList(node VarList){
    //VarList -> ParamDec COMMA VarList
    //VarList -> ParamDec
    InterCode code1 = translate_ParamDec(VarList->child[0]);
    if(VarList->child_num == 3){
        InterCode code2 = translate_VarList(VarList->child[2]);
        return link(code1, code2);
    }
    else{
        return code1;
    }
}
InterCode translate_ParamDec(node ParamDec){
    //ParamDec -> Specifier VarDec
    FieldList field = searchField(ParamDec->child[1]->child[0]->literal);
    Operand param = malloc(sizeof(struct Operand_));
    param->kind = VARIABLE;
    param->u.var_no = field->var_no;
    return param;
}
InterCode translate_CompSt(node CompSt){
    //CompSt -> LC DefList StmtList RC
    InterCode code1 = translate_DefList(CompSt->child[1]);
    InterCode code2 = translate_StmtList(CompSt->child[2]);
    return link(code1, code2);
}
InterCode translate_DefList(node DefList){
    //DefList -> Def DefList
    //DefList -> NULL
    if(DefList->child_num == 0){
        return NULL;
    }
    InterCode code1 = translate_Def(DefList->child[0]);
    InterCode code2 = translate_DefList(DefList->child[1]);
    return link(code1, code2);
}
InterCode translate_Cond(node Exp, Operand label_true, Operand label_false){
    if(!strcmp(Exp->child[1]->name,"RELOP")){
        Operand t1 = new_temp();
        Operand t2 = new_temp();
        InterCode code1 = translate_Exp(Exp->child[0], t1);
        InterCode code2 = translate_Exp(Exp->child[2], t2);
        InterCode code3 = malloc(sizeof(struct InterCode));
        code3.kind = IF;
        code3.u.if_goto.t1 = t1;
        Operand op = malloc(sizeof(struct Operand_));
        op->kind = RELOP;
        strcpy(op->u.name, Exp->child[1]->literal);
        code3.u.if_goto.op = t2;
        code3.u.if_goto.label_true = label_true;

        InterCode code4 = malloc(sizeof(struct InterCode));
        code4.kind = GOTO;
        code4.u.goto_label = label_false;
        return link(code1, link(code2, link(code3, code4)));
    }
    else if(!strcmp(child[0]->name, "NOT")){
        return translate_Cond(Exp->child[1], label_false, label_true);
    }
    else if(!strcmp(child[1]->name, "AND")){
        Operand label1 = new_label();
        InterCode code1 = translate_Cond(Exp->child[0], label1, label_false);
        InterCode code2 = translate_Cond(Exp->child[2], label_true, label_false);
        InterCode code3 = malloc(sizeof(struct InterCode));
        code3.kind = LABEL;
        code3.u.label = label1;
        return link(code1, link(code3, code2));
    }
    else if(!strcmp(child[1]->name, "OR")){
        Operand label1 = new_label();
        InterCode code1 = translate_Cond(Exp->child[0], label_true, label1);
        InterCode code2 = translate_Cond(Exp->child[2], label_true, label_false);
        InterCode code3 = malloc(sizeof(struct InterCode));
        code3.kind = LABEL;
        code3.u.label = label1;
        return link(code1, link(code3, code2));
    }
    else{
        Operand t1 = new_temp();
        InterCode code1 = translate_Exp(Exp, t1);
        InterCode code2 = malloc(sizeof(struct InterCode));
        code2.kind = IF;
        code2.u.if_goto.t1 = t1;
        Operand op = malloc(sizeof(struct Operand_));
        op->kind = RELOP;
        strcpy(op->u.name, "!=");
        code2.u.if_goto.op = op;
        Operand zero = create_Immediate(0);
        code2.u.if_goto.t2 = zero;
        code2.u.if_goto.label_true = label_true;
        InterCode code3 = malloc(sizeof(struct InterCode));
        code3.kind = GOTO;
        code3.u.goto_label = label_false;
        return link(code1, link(code2, code3));
    }
}
Intercode translate_Stmt(node Stmt){
    //Stmt -> Exp SEMI
    //Stmt -> CompSt
    //Stmt -> RETURN Exp SEMI
    //Stmt -> IF LP Exp RP Stmt
    //Stmt -> IF LP Exp RP Stmt ELSE Stmt
    //Stmt -> WHILE LP Exp RP Stmt

    if(!strcmp(Stmt->child[0]->name,"Exp") && !strcmp(Stmt->child[1]->name,"SEMI")){
        return translate_Exp(Stmt->child[0], NULL);
    }
    else if(!strcmp(Stmt->child[0]->name,"CompSt")){
        return translate_CompSt(Stmt->child[0]);
    }
    else if(!strcmp(Stmt->child[0]->name,"IF") && Stmt->child_num == 5){
        Operand label1 = new_label();
        Operand label2 = new_label();
        InterCode code1 = translate_Cond(Stmt->child[2], label1, label2);
        InterCode code2 = translate_Stmt(Stmt->child[4]);
        InterCode code3 = malloc(sizeof(struct InterCode));
        InterCode code4 = malloc(sizeof(struct InterCode));
        code3.kind = LABEL;
        code3.u.label = label1;
        code4.kind = LABEL;
        code4.u.label = label2;
        return link(code1, link(code3, link(code2, code4)));
    }
    else if(!strcmp(Stmt->child[0]->name,"IF") && Stmt->child_num == 7){
        Operand label1 = new_label();
        Operand label2 = new_label();
        Operand label3 = new_label();
        InterCode code1 = translate_Cond(Stmt->child[2], label1, label2);
        InterCode code2 = translate_Stmt(Stmt->child[4]);
        InterCode code3 = translate_Stmt(Stmt->child[6]);
        InterCode code4 = malloc(sizeof(struct InterCode));
        InterCode code5 = malloc(sizeof(struct InterCode));
        code4.kind = LABEL;
        code4.u.label = label1;
        code5.kind = LABEL;
        code5.u.label = label2;
        return link(code1, link(code4, link(code2, link(code5, code3))));
    }
    else if(!strcmp(Stmt->child[0]->name,"RETURN")){
        Operand t1 = new_temp();
        InterCode code1 = translate_Exp(Stmt->child[1], t1);
        InterCode code2 = malloc(sizeof(struct InterCode));
        code2.kind = RETURN;
        code2.u.return_value = t1;
        return link(code1, code2);
    }
    else if(!strcmp(Stmt->child[0]->name,"WHILE")){
        Operand label1 = new_label();
        Operand label2 = new_label();
        Operand label3 = new_label();
        InterCode code1 = malloc(sizeof(struct InterCode));
        InterCode code2 = malloc(sizeof(struct InterCode));
        InterCode code3 = malloc(sizeof(struct InterCode));
        InterCode code4 = malloc(sizeof(struct InterCode));
        code1.kind = LABEL;
        code1.u.label = label1;
        code2.kind = LABEL;
        code2.u.label = label2;
        code3.kind = LABEL;
        code3.u.label = label3;
        InterCode code5 = translate_Cond(Stmt->child[2], label2, label3);
        InterCode code6 = translate_Stmt(Stmt->child[4]);
        code4.kind = GOTO;
        code4.u.goto_label = label1;
        return link(code1, link(code5, link(code2, link(code6, link(code4, code3)))));
    }
}
InterCode translate_Args(node Args, Operand* args){
    //Args -> Exp COMMA Args
    //Args -> Exp
    // if(Args->child_num == 1){
    //     Operand t1 = new_temp();
    //     InterCode code1 = translate_Exp(Args->child[0], t1);
    //     *args = t1;
    //     return code1;
    // }
    // else{
    //     Operand t1 = new_temp();
    //     InterCode code1 = translate_Exp(Args->child[0], t1);
    //     InterCode code2 = translate_Args(Args->child[2], args);
    //     return link(code1, code2);
    // }
}
InterCode translate_Exp(node Exp,Operand place){
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
    if(!strcmp(Exp->child[0]->name, "INT")){
        struct Intercode code = malloc(sizeof(struct InterCode));
        int value = *(int*(Exp->child[0]->literal));
        code.kind = ASSIGN;
        code.u.assign.right.kind = CONSTANT;
        code.u.assign.right.u.value = value;  
        code.u.assign.left = place;
        return code;
    }
    else if(!strcmp(Exp->child[0]->name, "ID") && Exp->child_num == 1){
        struct Intercode code = malloc(sizeof(struct InterCode));
        FieldList field = searchField(Exp->child[0]->literal);
        code.kind = ASSIGN;
        code.u.assign.right.kind = VARIABLE;
        code.u.assign.right.u.var_no = field->var_no;
        code.u.assign.left = place;
        return code;
    }
    else if(!strcmp(Exp->child[0]->name, "Exp") && !strcmp(Exp->child[1]->name, "ASSIGNOP")){
        FieldList field = searchField(Exp->child[0]->child[0]->literal);
        Operand t1 = new_temp();
        struct Intercode code1 = translate_Exp(Exp->child[2], t1);
        struct InterCode code2 = malloc(sizeof(struct InterCode));
        struct InterCode code3 = malloc(sizeof(struct InterCode));
        code2.kind = ASSIGN;
        code2.u.assign.right.kind = VARIABLE;
        code2.u.assign.right.u.var_no = t1->u.var_no;
        code2.u.assign.left = place;
        code3.kind = ASSIGN;
        code3.u.assign.right.kind = VARIABLE;
        code3.u.assign.right.u.var_no = field->var_no;
        code3.u.assign.left = place;
        return link(code1, link(code2,code3));
    }
    else if(!strcmp(Exp->child[0]->name, "Exp") && (!strcmp(Exp->child[1]->name, "PLUS") 
    || !strcmp(Exp->child[1]->name, "MINUS") || !strcmp(Exp->child[1]->name, "STAR") || !strcmp(Exp->child[1]->name, "DIV"))){
        Operand t1 = new_temp();
        Operand t2 = new_temp();
        InterCode code1 = translate_Exp(Exp->child[0], t1);
        InterCode code2 = translate_Exp(Exp->child[2], t2);
        struct InterCode code3 = malloc(sizeof(struct InterCode));
        switch (Exp->child[1]->name)
        {
        case "PLUS":
            code3.kind = ADD;
            break;
        case "MINUS":
            code3.kind = SUB;
            break;
        case "STAR":
            code3.kind = MUL;
            break; 
        case "DIV":
            code3.kind = DIV;
            break;
        default:
            break;
        }
        code3.u.binop.result = place;
        code3.u.binop.op = t1;
        code3.u.binop.op2 = t2;
        return link(code1, link(code2, code3));
    }
    else if(!strcmp(Exp->child[0]->name, "MINUS")){
        Operand t1 = new_temp();
        InterCode code1 = translate_Exp(Exp->child[0], t1);
        InterCode code2 = malloc(sizeof(struct InterCode));
        Operand zero = create_Immediate(0);
        code2.kind = SUB;
        //NOT
        code2.u.binop.result = place;
        code2.u.binop.op = zero;
        code2.u.binop.op2 = t1;
        return link(code1, code2);
    }
    else if((!strcmp(Exp->child[0]->name, "Exp") && (!strcmp(Exp->child[1]->name,"RELOP") || !strcmp(Exp->child[1]->name,"AND") || !strcmp(Exp->child[1]->name,"OR"))) || !strcmp(Exp->child[0]->name, "NOT")){
        Operand label1 = new_label();
        Operand label2 = new_label();
        InterCode code0 = malloc(sizeof(struct InterCode));
        Operand zero = create_Immediate(0);
        code0.kind = ASSIGN;
        code0.u.assign.right = zero;
        code0.u.assign.left = place;

        InterCode code1 = translate_Cond(Exp, label1, label2);
        InterCode code2 = malloc(sizeof(struct InterCode));
        InterCode code3 = malloc(sizeof(struct InterCode));
        InterCode code4 = malloc(sizeof(struct InterCode));
        Operand one = create_Immediate(1);

        code2.kind = LABEL;
        code2.u.label = label1;
        code3.kind = ASSIGN;
        code3.u.assign.right = one;
        code3.u.assign.left = place;
        code4.kind = LABEL;
        code4.u.label = label2;
        return link(code0, link(code1, link(code2, link(code3, code4))));
    }
    else if(!strcmp(Exp->child[0]->name, "ID") && !strcmp(Exp->child[2]->name, "Args")){
        // FieldList field = searchField(Exp->child[0]->literal);
        // Operand func = malloc(sizeof(struct Operand_));
        // func->kind = FUNCTION;
        // func->u.var_no = field->var_no;
        // InterCode code1 = malloc(sizeof(struct InterCode));
        // code1.kind = ASSIGN;
        // code1.u.assign.right = func;
        // code1.u.assign.left = place;
        // InterCode code2 = translate_Args(Exp->child[2], field->argc);
        // return link(code1, code2);
    }
    else if(!strcmp(Exp->child[0]->name, "ID") && !strcmp(Exp->child[1]->name, "LP") && !strcmp(Exp->child[2]->name, "RP")){
        // FieldList field = searchField(Exp->child[0]->literal);
        // Operand func = malloc(sizeof(struct Operand_));
        // func->kind = FUNCTION;
        // func->u.var_no = field->var_no;
        // InterCode code1 = malloc(sizeof(struct InterCode));
        // code1.kind = ASSIGN;
        // code1.u.assign.right = func;
        // code1.u.assign.left = place;
        // return code1;
    }
    else if(!strcmp(Exp->child[0]->name, "Exp") && !strcmp(Exp->child[1]->name, "LB")){
        FieldList field = searchField(Exp->child[0]->child[0]->literal);
        Operand t1 = new_temp();
        Operand t2 = new_temp();
        InterCode code1 = translate_Exp(Exp->child[0], t1);
        InterCode code2 = translate_Exp(Exp->child[2], t2);
        InterCode code3 = malloc(sizeof(struct InterCode));
        code3.kind = ADD;
        code3.u.binop.result = place;
        code3.u.binop.op = t1;
        code3.u.binop.op2 = t2;
        return link(code1, link(code2, code3));
    }
}
int main(){
    node root = parse();
    semantic(root);
    InterCode code = translate_Program(root);
    print_Intercode(code);
}