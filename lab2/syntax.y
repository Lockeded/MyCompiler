%{
    #include <stdio.h>
    #include "Node.h"
    #include "lex.yy.c"
    #include "Semantic.h"
%}
%union{
    node type_node;
}

%token <type_node> INT FLOAT ID
%token <type_node> ERROR_INT8 ERROR_INT16 ERROR_FLOAT
%token <type_node> SEMI COMMA ASSIGNOP RELOP PLUS MINUS STAR DIV
%token <type_node> AND OR DOT NOT TYPE LP RP LB RB LC RC
%token <type_node> STRUCT RETURN IF ELSE WHILE


%type <type_node> Program ExtDefList ExtDef ExtDecList
%type <type_node> Specifier StructSpecifier OptTag Tag
%type <type_node> VarDec FunDec VarList ParamDec CompSt
%type <type_node> StmtList Stmt DefList Def DecList Dec Exp Args


%right ASSIGNOP
%left OR
%left AND
%left RELOP
%left PLUS MINUS
%left STAR DIV
%right NOT
%left LP RP LB RB DOT
%nonassoc ELSE

%%
Program : ExtDefList { $$= create_node("Program", 0, 1, create_child_list(1,(node []){$1}));print_tree($$,0);semantic($$);}
    ;
ExtDefList : ExtDef ExtDefList { $$ = create_node("ExtDefList", 0,2,create_child_list(2, (node[]){$1, $2})); }
    | /* 空规则 */ { $$ = create_node("NULL",-1,0,NULL);}
    ;
ExtDef : Specifier FunDec CompSt { $$= create_node("ExtDef", 0, 3, create_child_list(3, (node[]){$1, $2, $3})); }
    | Specifier FunDec SEMI {$$= create_node("ExtDef", 0, 3, create_child_list(3, (node[]){$1, $2, $3})); }
    | Specifier ExtDecList SEMI { $$= create_node("ExtDef", 0, 3, create_child_list(3, (node[]){$1, $2, $3})); }
    | Specifier SEMI { $$= create_node("ExtDef", 0, 2, create_child_list(2,(node[]){$1,$2})); }
    | error FunDec CompSt {}
    | error SEMI {}
    | error RP {}
    |  error RC {}
    | Specifier error SEMI {}
    | error Specifier SEMI {}
    ;
ExtDecList : VarDec { $$= create_node("ExtDecList", 0, 1, create_child_list(1,(node[]){$1})); }
    | VarDec COMMA ExtDecList { $$= create_node("ExtDecList", 0, 3, create_child_list(3, (node[]){$1, $2, $3})); }
    | VarDec error ExtDecList {}
    ;
Specifier : TYPE { $$= create_node("Specifier", 0, 1, create_child_list(1,(node[]){$1})); }
    | StructSpecifier { $$= create_node("Specifier", 0, 1, create_child_list(1,(node[]){$1})); }
    ;
StructSpecifier : STRUCT OptTag LC DefList RC { $$= create_node("StructSpecifier", 0, 5, create_child_list(5, (node[]){$1, $2, $3, $4, $5})); }
    | STRUCT Tag { $$= create_node("StructSpecifier", 0, 2, create_child_list(2, (node[]){$1, $2})); }
    | STRUCT  error RC {}
    | error OptTag LC DefList RC {}
    ;
OptTag : ID { $$= create_node("OptTag", 0, 1, create_child_list(1,(node[]){$1})); }
    | /* 空规则 */ { $$ = create_node("NULL",-1,0,NULL);; }
    ;
Tag : ID { $$= create_node("Tag", 0, 1, create_child_list(1,(node[]){$1})); }
    ;
VarDec : ID { $$= create_node("VarDec", 0, 1, create_child_list(1,(node[]){$1})); }
    | VarDec LB INT RB { $$= create_node("VarDec", 0, 4, create_child_list(4, (node[]){$1, $2, $3, $4})); }
    | VarDec LB INT error RB {}
    | VarDec LB error RB {}
    | error RB {}
    ;
FunDec :ID LP VarList RP { $$= create_node("FunDec", 0, 4, create_child_list(4, (node[]){$1, $2, $3, $4})); }
    | ID LP RP { $$= create_node("FunDec", 0, 3, create_child_list(3,(node[]){$1, $2, $3})); }
    | ID LP error RP {}
    | ID error RP {}
    | error LP VarList RP {}
    ;
VarList : ParamDec COMMA VarList { $$= create_node("VarList", 0, 3, create_child_list(3, (node[]){$1, $2, $3})); }
    | ParamDec { $$= create_node("VarList", 0, 1, create_child_list(1,(node[]){$1})); }
    ;
ParamDec : Specifier VarDec { $$= create_node("ParamDec", 0, 2, create_child_list(2, (node[]){$1, $2})); }
    ;
CompSt : LC DefList StmtList RC { $$= create_node("CompSt", 0, 4, create_child_list(4, (node[]){$1, $2, $3, $4})); }
    | error RC {}
    ;
StmtList : Stmt StmtList { $$= create_node("StmtList", 0, 2, create_child_list(2, (node[]){$1, $2})); }
    | /* 空规则 */ { $$ = create_node("NULL",-1,0,NULL);; }
    ;
Stmt : Exp SEMI { $$= create_node("Stmt", 0, 2, create_child_list(2,(node[]){$1, $2})); }
    | CompSt { $$= create_node("Stmt", 0, 1, create_child_list(1,(node[]){$1}));  }
    | RETURN Exp SEMI { $$= create_node("Stmt", 0, 3, create_child_list(3, (node[]){$1, $2, $3})); }
    | IF LP Exp RP Stmt { $$= create_node("Stmt", 0, 5, create_child_list(5, (node[]){$1, $2, $3, $4, $5})); }
    | IF LP Exp RP Stmt ELSE Stmt { $$= create_node("Stmt", 0, 7, create_child_list(7, (node[]){$1, $2, $3, $4, $5,$6, $7})); }
    | WHILE LP Exp RP Stmt { $$= create_node("Stmt", 0, 5, create_child_list(5, (node[]){$1, $2, $3, $4, $5})); }
     |  IF error ELSE Stmt {}
    | WHILE error RP {}
    | WHILE error RC {}
    | error SEMI {}
    | Exp error SEMI {}
    |RETURN Exp error {}
    | RETURN error SEMI {}
    ;
DefList : Def DefList { $$= create_node("DefList", 0, 2, create_child_list(2, (node[]){$1, $2})); }
    | /* 空规则 */ { $$ = create_node("NULL",-1,0,NULL);; }
    ;
Def : Specifier DecList SEMI { $$= create_node("Def", 0, 3, create_child_list(3, (node[]){$1, $2, $3})); }
    | Specifier error SEMI{}
    | error DecList SEMI {}
    ;
DecList : Dec { $$= create_node("DecList", 0, 1, create_child_list(1,(node[]){$1})); }
    | Dec COMMA DecList { $$= create_node("DecList", 0, 3, create_child_list(3, (node[]){$1, $2, $3})); }
    ;
Dec : VarDec { $$= create_node("Dec", 0, 1, create_child_list(1,(node[]){$1})); }
    | VarDec ASSIGNOP Exp { $$= create_node("Dec", 0, 3, create_child_list(3, (node[]){$1, $2,$3})); }
    ;
Exp : Exp ASSIGNOP Exp { $$= create_node("Exp", 0, 3, create_child_list(3, (node[]){$1, $2,$3})); }
    | Exp AND Exp { $$= create_node("Exp", 0, 3, create_child_list(3, (node[]){$1, $2,$3})); }
    | Exp OR Exp { $$= create_node("Exp", 0, 3, create_child_list(3, (node[]){$1, $2,$3})); }
    | Exp RELOP Exp { $$= create_node("Exp", 0, 3, create_child_list(3, (node[]){$1, $2,$3})); }
    | Exp PLUS Exp { $$= create_node("Exp", 0, 3, create_child_list(3, (node[]){$1, $2,$3})); }
    | Exp MINUS Exp { $$= create_node("Exp", 0, 3, create_child_list(3, (node[]){$1, $2,$3})); }
    | Exp STAR Exp { $$= create_node("Exp", 0, 3, create_child_list(3, (node[]){$1, $2,$3})); }
    | Exp DIV Exp { $$= create_node("Exp", 0, 3, create_child_list(3, (node[]){$1, $2,$3})); }
    | LP Exp RP { $$= create_node("Exp", 0, 3, create_child_list(3, (node[]){$1, $2, $3})); }
    | MINUS Exp { $$= create_node("Exp", 0, 2, create_child_list(2, (node[]){$1, $2})); }
    | NOT Exp { $$= create_node("Exp", 0, 2, create_child_list(2, (node[]){$1, $2})); }
    | ID LP Args RP { $$= create_node("Exp", 0, 4, create_child_list(4, (node[]){$1,$2, $3,$4})); }
    | ID LP RP { $$= create_node("Exp", 0, 3, create_child_list(3, (node[]){$1,$2, $3})); }
    | Exp LB Exp RB { $$= create_node("Exp", 0, 4, create_child_list(4, (node[]){$1, $2, $3, $4})); }
    | Exp DOT ID { $$= create_node("Exp", 0, 3, create_child_list(3, (node[]){$1, $2,$3})); }
    | ID { $$= create_node("Exp", 0, 1, create_child_list(1,(node[]){$1})); }
    | INT { $$= create_node("Exp", 0, 1, create_child_list(1,(node[]){$1})); }
    | FLOAT { $$= create_node("Exp", 0, 1, create_child_list(1,(node[]){$1})); }
    | ERROR_INT16 {}
    | ERROR_INT8 {}
    | ERROR_FLOAT {}
    | Exp ASSIGNOP error SEMI {}
    |  Exp AND error SEMI{}
    | Exp OR error SEMI {}
    | Exp RELOP error SEMI {}
    |  Exp PLUS error SEMI{}
    |  Exp MINUS error SEMI{}
    |  Exp STAR error SEMI{}
    |  Exp DIV error SEMI {}
    |   ID LP error SEMI {}
    |  Exp LB error RB {}
    ;
Args : Exp COMMA Args { $$= create_node("Args", 0, 3, create_child_list(3, (node[]){$1,$2, $3})); }
    | Exp { $$= create_node("Args", 0, 1, create_child_list(1,(node[]){$1})); }
    ;

%%
