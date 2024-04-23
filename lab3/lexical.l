%{
#include <stdio.h>
#include <stdlib.h>
#include "syntax.tab.h"
#include "Node.h"
%}
INT ((0|[1-9][0-9]*)|(0|0[1-7][0-7]*)|(0[Xx][0-9a-fA-F]+))
FLOAT ([0-9]+\.[0-9]+)|([0-9]*\.[0-9]+[Ee][+-]?[0-9]*)|([0-9]+\.[0-9]*[Ee][+-]?[0-9]*)
ERROR_INT8 0[0-7]*[8-9]+[0-7]*
ERROR_INT16 0[Xx][0-9a-fA-F]*[g-zG-Z]+[0-9a-fA-F]*
ERROR_FLOAT (([0-9]*\.[0-9]*)[eE])|(([0-9]*\.[0-9]*)[+-][eE][0-9]*)
ID [a-zA-Z_][a-zA-Z0-9_]*
SEMI ;
COMMA ,
ASSIGNOP =
RELOP \>|\<|\>=|\<=|==|!=
PLUS \+
MINUS \-
STAR \*
DIV \/
AND &&
OR \|\|
DOT \.
NOT \!
TYPE int|float
LP \(
RP \)
LB \[
RB \]
LC \{
RC \}
STRUCT struct
RETURN return
IF if
ELSE else
WHILE while
SPACE [ \r\t\n]+

%option yylineno

%%

{SPACE} {}
"//" {
    char c = input();
    while (c != '\n' && c != 0){
        c = input();
    }
}

"/*" {
    int state = 0; 
    char c;

    while (c != 1) {
        c = input();
        if(c == 0){
            error_A(yylineno,yytext,"unfinished comment");
            break;
        }
        switch (state) {
            case 0:
                if (c == '*') {
                    state = 1;
                }
                else if (c == '/'){
                    state = 2;
                }
                break;
            case 1:
                if (c == '*') {
                    state = 1;
                } else if (c == '/') {
                    state = -1;
                } else {
                    state = 0; 
                }
                break;
            case 2:
                if (c == '/'){
                    state = 2;
                }
                else if (c == '*'){
                    state = 0;
                }
                break;
        }
        if(state == -1){
            break;
        }
    }
}

{TYPE} {
  yylval.type_node = create_node("TYPE", yylineno, 0, NULL);
  set_literal(yylval.type_node,TYPE_ID, yytext);
  return TYPE;
}
{STRUCT} {
  yylval.type_node = create_node("STRUCT", yylineno, 0, NULL);
  return STRUCT;
}
{RETURN} {
  yylval.type_node = create_node("RETURN", yylineno, 0, NULL);
  return RETURN;
}
{IF} {
  yylval.type_node = create_node("IF", yylineno, 0, NULL);
  return IF;
}
{ELSE} {
  yylval.type_node = create_node("ELSE", yylineno, 0, NULL);
  return ELSE;
}
{WHILE} {
  yylval.type_node = create_node("WHILE", yylineno, 0, NULL);
  return WHILE;
}

{INT} {
  yylval.type_node = create_node("INT", yylineno, 0, NULL);
  set_literal(yylval.type_node, TYPE_INT, yytext);
  return INT;
}
{ERROR_INT8} { char * msg = "illegal INT8 number"; error_A(yylineno,yytext,msg); return ERROR_INT8;}
{ERROR_INT16} {char * msg = "illegal INT16 number"; error_A(yylineno,yytext,msg); return ERROR_INT16;}
{ERROR_FLOAT} { char * msg = "illegal FLOAT number"; error_A(yylineno,yytext,msg); return ERROR_FLOAT;}
{FLOAT} {
  yylval.type_node = create_node("FLOAT", yylineno, 0, NULL);
  set_literal(yylval.type_node, TYPE_FLOAT, yytext);
  return FLOAT;
}

{SEMI} {
  yylval.type_node = create_node("SEMI", yylineno, 0, NULL);
  return SEMI;
}
{COMMA} {
  yylval.type_node = create_node("COMMA", yylineno, 0, NULL);
  return COMMA;
}
{ASSIGNOP} {
  yylval.type_node = create_node("ASSIGNOP", yylineno, 0, NULL);
  return ASSIGNOP;
}
{PLUS} {
  yylval.type_node = create_node("PLUS", yylineno, 0, NULL);
  return PLUS;
}
{MINUS} {
  yylval.type_node = create_node("MINUS", yylineno, 0, NULL);
  return MINUS;
}
{STAR} {
  yylval.type_node = create_node("STAR", yylineno, 0, NULL);
  return STAR;
}
{DIV} {
  yylval.type_node = create_node("DIV", yylineno, 0, NULL);
  return DIV;
}
{AND} {
  yylval.type_node = create_node("AND", yylineno, 0, NULL);
  return AND;
}
{OR} {
  yylval.type_node = create_node("OR", yylineno, 0, NULL);
  return OR;
}
{DOT} {
  yylval.type_node = create_node("DOT", yylineno, 0, NULL);
  return DOT;
}
{NOT} {
  yylval.type_node = create_node("NOT", yylineno, 0, NULL);
  return NOT;
}

{LP} {
  yylval.type_node = create_node("LP", yylineno, 0, NULL);
  return LP;
}
{RP} {
  yylval.type_node = create_node("RP", yylineno, 0, NULL);
  return RP;
}
{LB} {
  yylval.type_node = create_node("LB", yylineno, 0, NULL);
  return LB;
}
{RB} {
  yylval.type_node = create_node("RB", yylineno, 0, NULL);
  return RB;
}
{LC} {
  yylval.type_node = create_node("LC", yylineno, 0, NULL);
  return LC;
}
{RC} {
  yylval.type_node = create_node("RC", yylineno, 0, NULL);
  return RC;
}
{RELOP} {
  yylval.type_node = create_node("RELOP", yylineno, 0, NULL);
  return RELOP;
}
{ID} {
  yylval.type_node = create_node("ID", yylineno, 0, NULL);
  set_literal(yylval.type_node, TYPE_ID, yytext);
  return ID;
}
. {
    error_A(yylineno,yytext,NULL);
}

%%
int main(int argc, char** argv){
    if (argc <= 1) return 1;
    FILE* f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }
    yyrestart(f);
    yyparse();
    return 0;
}