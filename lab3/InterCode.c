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
    struct Intercode code;
    if(!strcmp(Exp->child[0]->name, "INT")){
        int value = *(int*(Exp->child[0]->literal));
        code.kind = ASSIGN;
        code.u.assign.right.kind = CONSTANT;
        code.u.assign.right.u.value = value;  
        code.u.assign.left = place;
        return code;
    }
    else if(!strcmp(Exp->child[0]->name, "ID")){
        FieldList field = searchField(Exp->child[0]->literal);
        code.kind = ASSIGN;
        code.u.assign.right.kind = VARIABLE;
        code.u.assign.right.u.var_no = field->var_no;
        code.u.assign.left = place;
        return code;
    }
    else if(!strcmp(Exp->child[0]->name, "Exp") && !strcmp(Exp->child[1]->name, "ASSIGNOP")){
        FieldList field = searchField(Exp->child[0]->child[0]->literal);
        Operand t1 = malloc(sizeof(struct Operand_));
        t1->kind = VARIABLE;
        t1->u.var_no = field->var_no;
        struct Intercode code1 = translate_Exp(Exp->child[2], t1);
        InterCode code2 = 
        code.kind = ASSIGN;
        code.u.assign.right = t1;
        code.u.assign.left = place;
        return code;
    }
    else if(!strcmp(Exp->child[0]->name, "Exp") && !strcmp(Exp->child[1]->name, "PLUS")){
        Operand t1 = malloc(sizeof(struct Operand_));
        t1->kind = VARIABLE;
        t1->u.var_no = Exp->child[0]->var_no;
        Operand t2 = malloc(sizeof(struct Operand_));
        t2->kind = VARIABLE;
        t2->u.var_no = Exp->child[2]->var_no;
        code.kind = ADD;
        code.u.binop.result = place;
        code.u.binop.op = t1;
        code.u.binop.op2 = t2;
        return code;
    }
    else if(!strcmp(Exp->child[0]->name, "Exp") && !strcmp(Exp->child[1]->name, "MINUS")){
        Operand t1 = malloc(sizeof(struct Operand_));
        t1->kind = VARIABLE;
        t1->u.var_no = Exp->child[0]->var_no;
        Operand t2 = malloc(sizeof(struct Operand_));
        t2->kind = VARIABLE;
        t2->u.var_no = Exp->child[2]->var_no;
        code.kind = SUB;
        code.u.binop.result = place;
        code.u.binop.op = t1;
        code.u.binop.op2 = t2;
        return code;
    }
    else if(!strcmp(Exp->child[0]->name, "Exp")
}