#include "InterCode.h"
InterCode head=NULL,tail=NULL;
extern FieldList HeadField;
int var_no = 0;
int label_no = 0;
void insert_Intercode(InterCode code){
    if (head == NULL) {
        head = code;
        tail = code;
        while (tail->next != NULL) {
            tail = tail->next;
        }
    } else {
        tail->next = code;
        code->prev = tail;
        while (code->next != NULL) {
            code = code->next;
        }
        tail = code; 
    }
}
void print_Intercode(){
    InterCode p = head;
    while (p != NULL){
        switch (p->kind)
        {
            case ASSIGN_:
                if(p->u.assign.left->kind == VARIABLE_){
                    if(p->u.assign.right->kind == VARIABLE_){
                        printf("%s := %s\n", p->u.assign.left->u.name, p->u.assign.right->u.name);
                    }
                    else if(p->u.assign.right->kind == CONSTANT_){
                        printf("%s := #%d\n", p->u.assign.left->u.name, p->u.assign.right->u.value);
                    }
                    else if(p->u.assign.right->kind == ADDRESS_){
                        printf("%s := &%s\n", p->u.assign.left->u.name, p->u.assign.right->u.name);
                    }
                    else if(p->u.assign.right->kind == DER_){
                        printf("%s := *%s\n", p->u.assign.left->u.name, p->u.assign.right->u.name);
                    }
                }
                else if(p->u.assign.left->kind == DER_){
                    if(p->u.assign.right->kind == VARIABLE_){
                        printf("*%s := %s\n", p->u.assign.left->u.name, p->u.assign.right->u.name);
                    }
                    else if(p->u.assign.right->kind == CONSTANT_){
                        printf("*%s := #%d\n", p->u.assign.left->u.name, p->u.assign.right->u.value);
                    }
                    else if(p->u.assign.right->kind == ADDRESS_){
                        printf("*%s := &%s\n", p->u.assign.left->u.name, p->u.assign.right->u.name);
                    }
                    else if(p->u.assign.right->kind == DER_){
                        printf("*%s := *%s\n", p->u.assign.left->u.name, p->u.assign.right->u.name);
                    }
                }
                else if(p->u.assign.left->kind == ADDRESS_){
                    if(p->u.assign.right->kind == VARIABLE_){
                        printf("&%s := %s\n", p->u.assign.left->u.name, p->u.assign.right->u.name);
                    }
                    else if(p->u.assign.right->kind == CONSTANT_){
                        printf("&%s := #%d\n", p->u.assign.left->u.name, p->u.assign.right->u.value);
                    }
                    else if(p->u.assign.right->kind == ADDRESS_){
                        printf("&%s := &%s\n", p->u.assign.left->u.name, p->u.assign.right->u.name);
                    }
                    else if(p->u.assign.right->kind == DER_){
                        printf("&%s := *%s\n", p->u.assign.left->u.name, p->u.assign.right->u.name);
                    }
                }
                break;
            case ADD_:
                if(p->u.binop.result->kind == VARIABLE_){
                    if(p->u.binop.op->kind == VARIABLE_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := %s + %s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := %s + #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := %s + &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := %s + *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                    }
                    if(p->u.binop.op->kind == CONSTANT_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := #%d + %s\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := #%d + #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := #%d + &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := #%d + *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.name);
                        }
                    }
                    if(p->u.binop.op->kind == ADDRESS_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := &%s + %s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := &%s + #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := &%s + &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := &%s + *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                    }
                    if(p->u.binop.op->kind == DER_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := *%s + %s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := *%s + #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := *%s + &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := *%s + *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                    }
                }
                break;
            case SUB_:
                if(p->u.binop.result->kind == VARIABLE_){
                    if(p->u.binop.op->kind == VARIABLE_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := %s - %s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := %s - #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := %s - &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := %s - *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                    }
                    if(p->u.binop.op->kind == CONSTANT_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := #%d - %s\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := #%d - #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := #%d - &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := #%d - *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.name);
                        }
                    }
                    if(p->u.binop.op->kind == ADDRESS_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := &%s - %s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := &%s - #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := &%s - &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := &%s - *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                    }
                    if(p->u.binop.op->kind == DER_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := *%s - %s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := *%s - #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := *%s - &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := *%s - *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                    }
                }
                break;
            case MUL_:
                if(p->u.binop.result->kind == VARIABLE_){
                    if(p->u.binop.op->kind == VARIABLE_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := %s * %s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := %s * #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := %s * &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := %s * *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                    }
                    if(p->u.binop.op->kind == CONSTANT_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := #%d * %s\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := #%d * #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := #%d * &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := #%d * *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.name);
                        }
                    }
                    if(p->u.binop.op->kind == ADDRESS_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := &%s * %s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := &%s * #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := &%s * &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := &%s * *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                    }
                    if(p->u.binop.op->kind == DER_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := *%s * %s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := *%s * #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := *%s * &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := *%s * *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                    }
                }
                break;
            case DIV_: 
                if(p->u.binop.result->kind == VARIABLE_){
                    if(p->u.binop.op->kind == VARIABLE_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := %s / %s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := %s / #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := %s / &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := %s / *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                    }
                    if(p->u.binop.op->kind == CONSTANT_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := #%d / %s\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := #%d / #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := #%d / &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := #%d / *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.value, p->u.binop.op2->u.name);
                        }
                    }
                    if(p->u.binop.op->kind == ADDRESS_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := &%s / %s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := &%s / #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := &%s / &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := &%s / *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                    }
                    if(p->u.binop.op->kind == DER_){
                        if(p->u.binop.op2->kind == VARIABLE_){
                            printf("%s := *%s / %s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == CONSTANT_){
                            printf("%s := *%s / #%d\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.value);
                        }
                        else if(p->u.binop.op2->kind == ADDRESS_){
                            printf("%s := *%s / &%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                        else if(p->u.binop.op2->kind == DER_){
                            printf("%s := *%s / *%s\n", p->u.binop.result->u.name, p->u.binop.op->u.name, p->u.binop.op2->u.name);
                        }
                    }
                }
                break;
            case GOTO_:
                printf("GOTO %s\n", p->u.goto_label->u.name);
                break;
            case RETURN_:
                if(p->u.ret->kind == VARIABLE_){
                    printf("RETURN %s\n", p->u.ret->u.name);
                }
                else if(p->u.ret->kind == CONSTANT_){
                    printf("RETURN #%d\n", p->u.ret->u.value);
                }
                else if(p->u.ret->kind == ADDRESS_){
                    printf("RETURN &%s\n", p->u.ret->u.name);
                }
                else if(p->u.ret->kind == DER_){
                    printf("RETURN *%s\n", p->u.ret->u.name);
                }
                break;
            case LABEL_:
                printf("LABEL %s :\n", p->u.label->u.name);
                break;
            case IF_:
                    if(p->u.if_goto.t1->kind == VARIABLE_){
                        if(p->u.if_goto.t2->kind == VARIABLE_){
                            printf("IF %s %s %s GOTO %s\n", p->u.if_goto.t1->u.name,p->u.if_goto.op->u.name, p->u.if_goto.t2->u.name, p->u.if_goto.label_true->u.name);
                        }
                        else{
                            printf("IF %s %s #%d GOTO %s\n", p->u.if_goto.t1->u.name,p->u.if_goto.op->u.name, p->u.if_goto.t2->u.value, p->u.if_goto.label_true->u.name);
                        }
                    }
                break;
            case READ_:
                printf("READ %s\n", p->u.read->u.name);
                break;
            case WRITE_:
                printf("WRITE %s\n", p->u.write->u.name);
                break;
            case CALL_:
                printf("%s := CALL %s\n", p->u.call.result->u.name, p->u.call.func->u.name);
                break;
            case ARG_:
                printf("ARG %s\n", p->u.arg->u.name);
                break;
            case DEC_:
                printf("DEC %s %d\n", p->u.dec.var->u.name, p->u.dec.size->u.value);
                break;
            case PARAM_:
                printf("PARAM %s\n", p->u.call.func->u.name);
                break;
            case FUNCTION_:
                printf("FUNCTION %s :\n", p->u.call.func->u.name);
                break;
            default:
                break;
        }
        p = p->next;
    }
}
Operand new_temp(){
    Operand temp = (Operand)malloc(sizeof(struct Operand_));
    temp->kind = VARIABLE_;
    var_no++;
    sprintf(temp->u.name,"t%d",var_no);
    return temp;
}
Operand new_label(){
    Operand label = (Operand)malloc(sizeof(struct Operand_));
    label->kind = LABEL_;
    label_no++;
    sprintf(label->u.name,"label%d",label_no);
    return label;
}
InterCode link_(InterCode code1, InterCode code2){
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
    imm->kind = CONSTANT_;
    imm->u.value = value;
    return imm;
}
void translate_Program(node Program){
    //Program -> ExtDefList
    translate_ExtDefList(Program->child[0]);
    print_Intercode();
}
void translate_ExtDefList(node ExtDefList){
    //ExtDefList -> ExtDef ExtDefList
    //ExtDefList -> NULL
    if(ExtDefList->child_num == 0){
        return;
    }
    translate_ExtDef(ExtDefList->child[0]);
    translate_ExtDefList(ExtDefList->child[1]);
}
void translate_ExtDef(node ExtDef){
    //ExtDef -> Specifier ExtDecList SEMI
    //ExtDef -> Specifier FunDec CompSt
    //ExtDef -> Specifier FunDec SEMI

    if(!strcmp(ExtDef->child[1]->name, "ExtDecList")){
        translate_ExtDecList(ExtDef->child[1]);
    }
    else{
        translate_FunDec(ExtDef->child[1]);
        translate_CompSt(ExtDef->child[2]);
    }
}
void translate_ExtDecList(node ExtDecList){
    //ExtDecList -> VarDec
    //ExtDecList -> VarDec COMMA ExtDecList
    if(ExtDecList->child_num == 1){
        translate_VarDec(ExtDecList->child[0]);
    }
    else{
        translate_VarDec(ExtDecList->child[0]);
        translate_ExtDecList(ExtDecList->child[2]);
    }
}
void translate_VarDec(node VarDec){
    //VarDec -> ID
    //VarDec -> VarDec LB INT RB
    if(VarDec->child_num == 1){
        return;
    }
    else{
        Operand size = create_Immediate(4 *(*(int*)VarDec->child[2]->literal));
        Operand ID = malloc(sizeof(struct Operand_));
        ID->kind = VARIABLE_;
        strcpy(ID->u.name, VarDec->child[0]->literal);
        InterCode code = (InterCode)malloc(sizeof(struct InterCode_));
        code->kind = DEC_;
        code->u.dec.size = size;
        code->u.dec.var = ID;
        insert_Intercode(code);
    }
}
void translate_FunDec(node FunDec){
    //FunDec -> ID LP VarList RP
    //FunDec -> ID LP RP
    FieldList field = searchField(FunDec->child[0]->literal);
    InterCode code = (InterCode)malloc(sizeof(struct InterCode_));
    code->kind = FUNCTION_;
    code->u.call.func = (Operand)malloc(sizeof(struct Operand_));
    strcpy(code->u.call.func->u.name, FunDec->child[0]->literal);
    insert_Intercode(code);
    if(FunDec->child_num == 4){
        translate_VarList(FunDec->child[2]);
    }
}
void translate_VarList(node VarList){
    //VarList -> ParamDec COMMA VarList
    //VarList -> ParamDec
    translate_ParamDec(VarList->child[0]);
    if(VarList->child_num == 3){
        translate_VarList(VarList->child[2]);
    }
}
void translate_ParamDec(node ParamDec){
    //ParamDec -> Specifier VarDec
    FieldList field = searchField(ParamDec->child[1]->child[0]->literal);
    InterCode code = (InterCode)malloc(sizeof(struct InterCode_));
    code->kind = PARAM_;
    code->u.call.func = (Operand)malloc(sizeof(struct Operand_));
    strcpy(code->u.call.func->u.name, field->name);
    insert_Intercode(code);
}
void translate_CompSt(node CompSt){
    //CompSt -> LC DefList StmtList RC
    translate_DefList(CompSt->child[1]);
    translate_StmtList(CompSt->child[2]);
}
void translate_StmtList(node StmtList){
    //StmtList -> Stmt StmtList
    //StmtList -> NULL
    if(StmtList->child_num == 0){
        return;
    }
    InterCode code = translate_Stmt(StmtList->child[0]);
    insert_Intercode(code);
    translate_StmtList(StmtList->child[1]);
}
void translate_DefList(node DefList){
    //DefList -> Def DefList
    //DefList -> NULL
    if(DefList->child_num == 0){
        return;
    }
    translate_Def(DefList->child[0]);
    translate_DefList(DefList->child[1]);
}
void translate_Def(node Def){
    //Def -> Specifier DecList SEMI
    translate_DecList(Def->child[1]);
}
void translate_DecList(node DecList){
    //DecList -> Dec
    //DecList -> Dec COMMA DecList
    translate_Dec(DecList->child[0]);
    if(DecList->child_num == 3){
        translate_DecList(DecList->child[2]);
    }
}
void translate_Dec(node Dec){
    //Dec -> VarDec
    //Dec -> VarDec ASSIGNOP Exp
    if(Dec->child_num == 1){
        translate_VarDec(Dec->child[0]);
    }
    else{
        Operand t1 = new_temp();
        InterCode code1 = translate_Exp(Dec->child[2], t1);
        FieldList field = searchField(Dec->child[0]->child[0]->literal);
        Operand dec_name = malloc(sizeof(struct Operand_));
        dec_name->kind = VARIABLE_;
        strcpy(dec_name->u.name, Dec->child[0]->child[0]->literal);
        InterCode code2 = (InterCode)malloc(sizeof(struct InterCode_));
        code2->kind = ASSIGN_;
        code2->u.assign.right = t1;
        code2->u.assign.left = dec_name;
        insert_Intercode(link_(code1, code2));
    }
}
InterCode translate_Cond(node Exp, Operand label_true, Operand label_false){
    if(!strcmp(Exp->child[1]->name,"RELOP")){
        Operand t1 = new_temp();
        Operand t2 = new_temp();
        InterCode code1 = translate_Exp(Exp->child[0], t1);
        InterCode code2 = translate_Exp(Exp->child[2], t2);
        Operand op = (Operand)malloc(sizeof(struct Operand_));
        op->kind = RELOP_;
        strcpy(op->u.name, Exp->child[1]->literal);
        InterCode code3 = (InterCode)malloc(sizeof(struct InterCode_));
        code3->kind = IF_;
        code3->u.if_goto.t1 = t1;
        code3->u.if_goto.op = op;
        code3->u.if_goto.t2 = t2;
        code3->u.if_goto.label_true = label_true;
        InterCode code4 = (InterCode)malloc(sizeof(struct InterCode_));
        code4->kind = GOTO_;
        code4->u.goto_label = label_false;
        return link_(link_(link_(code1, code2), code3), code4);
    }
    else if(!strcmp(Exp->child[0]->name, "NOT")){
        return translate_Cond(Exp->child[1], label_false, label_true);
    }
    else if(!strcmp(Exp->child[1]->name, "AND")){
        Operand label1 = new_label();
        InterCode code1 = translate_Cond(Exp->child[0], label1, label_false);
        InterCode code2 = translate_Cond(Exp->child[2], label_true, label_false);
        InterCode code3 = (InterCode)malloc(sizeof(struct InterCode_));
        code3->kind = LABEL_;
        code3->u.label = label1;
        return link_(code1, link_(code3, code2));
    }
    else if(!strcmp(Exp->child[1]->name, "OR")){
        Operand label1 = new_label();
        InterCode code1 = translate_Cond(Exp->child[0], label_true, label1);
        InterCode code2 = translate_Cond(Exp->child[2], label_true, label_false);
        InterCode code3 = (InterCode)malloc(sizeof(struct InterCode_));
        code3->kind = LABEL_;
        code3->u.label = label1;
        return link_(code1, link_(code3, code2));
    }
    else{
        Operand t1 = new_temp();
        InterCode code1 = translate_Exp(Exp, t1);
        InterCode code2 = (InterCode)malloc(sizeof(struct InterCode_));
        code2->kind = IF_;
        code2->u.if_goto.t1 = t1;
        Operand op = malloc(sizeof(struct Operand_));
        op->kind = RELOP_;
        strcpy(op->u.name, "!=");
        code2->u.if_goto.op = op;
        Operand zero = create_Immediate(0);
        code2->u.if_goto.t2 = zero;
        code2->u.if_goto.label_true = label_true;
        InterCode code3 = (InterCode)malloc(sizeof(struct InterCode_));
        code3->kind = GOTO_;
        code3->u.goto_label = label_false;
        return link_(code1, link_(code2, code3));
    }
}
InterCode translate_Stmt(node Stmt){
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
        translate_CompSt(Stmt->child[0]);
    }
    else if(!strcmp(Stmt->child[0]->name,"IF") && Stmt->child_num == 5){
        Operand label1 = new_label();
        Operand label2 = new_label();
        InterCode code1 = translate_Cond(Stmt->child[2], label1, label2);
        InterCode code2 = translate_Stmt(Stmt->child[4]);
        InterCode code3 = (InterCode)malloc(sizeof(struct InterCode_));
        InterCode code4 = (InterCode)malloc(sizeof(struct InterCode_));
        code3->kind = LABEL_;
        code3->u.label = label1;
        code4->kind = LABEL_;
        code4->u.label = label2;
        return link_(code1, link_(code3, link_(code2, code4)));
    }
    else if(!strcmp(Stmt->child[0]->name,"IF") && Stmt->child_num == 7){
        Operand label1 = new_label();
        Operand label2 = new_label();
        Operand label3 = new_label();
        InterCode code1 = translate_Cond(Stmt->child[2], label1, label2);
        InterCode code2 = translate_Stmt(Stmt->child[4]);
        InterCode code3 = translate_Stmt(Stmt->child[6]);
        InterCode code4 = (InterCode)malloc(sizeof(struct InterCode_));
        InterCode code5 = (InterCode)malloc(sizeof(struct InterCode_));
        code4->kind = LABEL_;
        code4->u.label = label1;
        code5->kind = LABEL_;
        code5->u.label = label2;
        InterCode code6 = (InterCode)malloc(sizeof(struct InterCode_));
        code6->kind = GOTO_;
        code6->u.goto_label = label3;
        InterCode code7 = (InterCode)malloc(sizeof(struct InterCode_));
        code7->kind = LABEL_;
        code7->u.label = label3;
        return link_(code1, link_(code4, link_(code2, link_(code6, link_(code5, link_(code3, code7))))));
    }
    else if(!strcmp(Stmt->child[0]->name,"RETURN")){
        Operand t1 = new_temp();
        InterCode code1 = translate_Exp(Stmt->child[1], t1);
        InterCode code2 = (InterCode)malloc(sizeof(struct InterCode_));
        code2->kind = RETURN_;
        code2->u.ret = t1;
        return link_(code1, code2);
    }
    else if(!strcmp(Stmt->child[0]->name,"WHILE")){
        Operand label1 = new_label();
        Operand label2 = new_label();
        Operand label3 = new_label();
        InterCode code1 = (InterCode)malloc(sizeof(struct InterCode_));
        InterCode code2 = (InterCode)malloc(sizeof(struct InterCode_));
        InterCode code3 = (InterCode)malloc(sizeof(struct InterCode_));
        InterCode code4 = (InterCode)malloc(sizeof(struct InterCode_));
        code1->kind = LABEL_;
        code1->u.label = label1;
        code2->kind = LABEL_;
        code2->u.label = label2;
        code3->kind = LABEL_;
        code3->u.label = label3;
        InterCode code5 = translate_Cond(Stmt->child[2], label2, label3);
        InterCode code6 = translate_Stmt(Stmt->child[4]);
        code4->kind = GOTO_;
        code4->u.goto_label = label1;
        return link_(code1, link_(code5, link_(code2, link_(code6, link_(code4, code3)))));
    }
}
InterCode translate_Args(node Args, Operand* args, int num){
    //Args -> Exp COMMA Args
    //Args -> Exp
    if(Args->child_num == 1){
        Operand t1 = new_temp();
        InterCode code1 = translate_Exp(Args->child[0], t1);
        args[num] = t1;
        return code1;
    }
    else{
        Operand t1 = new_temp();
        InterCode code1 = translate_Exp(Args->child[0], t1);
        args[num] = t1;
        InterCode code2 = translate_Args(Args->child[2], args, num+1);
        return link_(code1, code2);
    }
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
    if(Exp->child[0]->literal_type == TYPE_INT || Exp->child[0]->literal_type == TYPE_FLOAT){
        InterCode code = (InterCode)malloc(sizeof(struct InterCode_));
        int value = *((int*)(Exp->child[0]->literal));
        code->kind = ASSIGN_;
        code->u.assign.right = (Operand)malloc(sizeof(struct Operand_));
        code->u.assign.right->kind = CONSTANT_;
        code->u.assign.right->u.value = value;  
        code->u.assign.left = place;
        return code;
    }
    else if(Exp->child[0]->literal_type == TYPE_ID && Exp->child_num == 1){
        InterCode code = (InterCode)malloc(sizeof(struct InterCode_));
        code->kind = ASSIGN_;
        code->u.assign.right = (Operand)malloc(sizeof(struct Operand_));
        code->u.assign.right->kind = VARIABLE_;
        strcpy(code->u.assign.right->u.name, Exp->child[0]->literal);
        code->u.assign.left = place;
        return code;
    }
    else if(!strcmp(Exp->child[0]->name, "Exp") && !strcmp(Exp->child[1]->name, "ASSIGNOP")){
        FieldList field = searchField(Exp->child[0]->child[0]->literal);
        Operand t1 = new_temp();
        InterCode code1 = translate_Exp(Exp->child[2], t1);
        Operand v1 = (Operand)malloc(sizeof(struct Operand_));
        v1->kind = VARIABLE_;
        strcpy(v1->u.name, Exp->child[0]->child[0]->literal);
        InterCode code2 = (InterCode)malloc(sizeof(struct InterCode_));
        code2->kind = ASSIGN_;
        code2->u.assign.right = t1;
        code2->u.assign.left = v1;
        if(place != NULL){
            InterCode code3 = (InterCode)malloc(sizeof(struct InterCode_));
            code3->kind = ASSIGN_;
            code3->u.assign.right = v1;
            code3->u.assign.left = place;
            return link_(code1, link_(code2, code3));
        }
        else{
            return link_(code1, code2);
        }
    }
    else if(!strcmp(Exp->child[0]->name, "Exp") && (!strcmp(Exp->child[1]->name, "PLUS") 
    || !strcmp(Exp->child[1]->name, "MINUS") || !strcmp(Exp->child[1]->name, "STAR") || !strcmp(Exp->child[1]->name, "DIV"))){
        Operand t1 = new_temp();
        Operand t2 = new_temp();
        InterCode code1 = translate_Exp(Exp->child[0], t1);
        InterCode code2 = translate_Exp(Exp->child[2], t2);
        InterCode code3 = (InterCode)malloc(sizeof(struct InterCode_));
        if(!strcmp(Exp->child[1]->name, "PLUS")){
            code3->kind = ADD_;
        }
        else if(!strcmp(Exp->child[1]->name, "MINUS")){
            code3->kind = SUB_;
        }
        else if(!strcmp(Exp->child[1]->name, "STAR")){
            code3->kind = MUL_;
        }
        else if(!strcmp(Exp->child[1]->name, "DIV")){
            code3->kind = DIV_;
        }
        code3->u.binop.result = place;
        code3->u.binop.op = t1;
        code3->u.binop.op2 = t2;
        return link_(code1, link_(code2, code3));
    }
    else if(!strcmp(Exp->child[0]->name, "MINUS")){
        Operand t1 = new_temp();
        InterCode code1 = translate_Exp(Exp->child[1], t1);
        InterCode code2 = (InterCode)malloc(sizeof(struct InterCode_));
        Operand zero = create_Immediate(0);
        code2->kind = SUB_;
        //NOT
        code2->u.binop.result = place;
        code2->u.binop.op = zero;
        code2->u.binop.op2 = t1;
        return link_(code1, code2);
    }
    else if((!strcmp(Exp->child[0]->name, "Exp") && (!strcmp(Exp->child[1]->name,"RELOP") || !strcmp(Exp->child[1]->name,"AND") || !strcmp(Exp->child[1]->name,"OR"))) || !strcmp(Exp->child[0]->name, "NOT")){
        Operand label1 = new_label();
        Operand label2 = new_label();
        InterCode code0 = (InterCode)malloc(sizeof(struct InterCode_));
        Operand zero = create_Immediate(0);
        code0->kind = ASSIGN_;
        code0->u.assign.right = zero;
        code0->u.assign.left = place;

        InterCode code1 = translate_Cond(Exp, label1, label2);
        InterCode code2 = (InterCode)malloc(sizeof(struct InterCode_));
        InterCode code3 = (InterCode)malloc(sizeof(struct InterCode_));
        InterCode code4 = (InterCode)malloc(sizeof(struct InterCode_));
        Operand one = create_Immediate(1);

        code2->kind = LABEL_;
        code2->u.label = label1;
        code3->kind = ASSIGN_;
        code3->u.assign.right = one;
        code3->u.assign.left = place;
        code4->kind = LABEL_;
        code4->u.label = label2;
        return link_(code0, link_(code1, link_(code2, link_(code3, code4))));
    }
    else if(Exp->child[0]->literal_type == TYPE_ID && !strcmp(Exp->child[1]->name, "LP") && Exp->child_num == 4 ){
        FieldList field = searchField(Exp->child[0]->literal);
        int argc = field->argc -1;
        Operand Args[MAX_NAME_LEN];
        InterCode code1 = translate_Args(Exp->child[2], Args, argc);
        if(!strcmp(field->name, "write")){
            InterCode code2 = (InterCode)malloc(sizeof(struct InterCode_));
            code2->kind = WRITE_;
            code2->u.write = Args[0];
            return link_(code1, code2);
        }
        else{
            for(int i = 0; i < argc; i++){
                InterCode code2 = (InterCode)malloc(sizeof(struct InterCode_));
                code2->kind = ARG_;
                code2->u.arg = Args[i];
                code1 = link_(code1, code2);
            }
            InterCode code3 = (InterCode)malloc(sizeof(struct InterCode_));
            code3->kind = CALL_;
            code3->u.call.func = (Operand)malloc(sizeof(struct Operand_));
            strcpy(code3->u.call.func->u.name, field->name);
            code3->u.call.result = place;
            return link_(code1, code3);
        }
    }
    else if(Exp->child[0]->literal_type == TYPE_ID && !strcmp(Exp->child[1]->name, "LP") && !strcmp(Exp->child[2]->name, "RP")){
        FieldList field = searchField(Exp->child[0]->literal);
        InterCode code = (InterCode)malloc(sizeof(struct InterCode_));
        if (!strcmp(field->name,"read")){
            code->kind = READ_;
            code->u.read = place;
            return code;
        }
        else{
            code->kind = CALL_;
            code->u.call.func = (Operand)malloc(sizeof(struct Operand_));
            strcpy(code->u.call.func->u.name, field->name);
            code->u.call.result = place;
            return code;
        }
    }
    else if(!strcmp(Exp->child[0]->name, "Exp") && !strcmp(Exp->child[1]->name, "LB")){
        FieldList field = searchField(Exp->child[0]->child[0]->literal);
        Operand t1 = new_temp();
        Operand t2 = new_temp();
        InterCode code1 = translate_Exp(Exp->child[0], t1);
        InterCode code2 = translate_Exp(Exp->child[2], t2);
        InterCode code3 = (InterCode)malloc(sizeof(struct InterCode_));
        code3->kind = ADD_;
        code3->u.binop.result = place;
        code3->u.binop.op = t1;
        code3->u.binop.op2 = t2;
        return link_(code1, link_(code2, code3));
    }
}