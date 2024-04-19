//
// Created by LIRUIBO on 24-3-17.
//
#ifndef POC_TREE_H
#define POC_TREE_H
extern int yylineno;
typedef enum {
    TYPE_INT,
    TYPE_ID,
    TYPE_FLOAT
} ValueType;
struct tree_node{
    char* name;
    int line;
    struct tree_node** child;
    int child_num;
    void* literal;
};
typedef struct tree_node *node;
node create_node(char* name,int line, int child_num, node* childlist);
int get_line(node node);
void set_literal(node node,ValueType type, void* value);
node* create_child_list(int num_children, node children[]);
void print_tree(node head,int depth);
void print_node(node node);
int my_stoi(char* value);
float my_stof(char* value);
void error_A(int line,char* character, char* msg);
void yyerror(char* msg);
#endif //POC_TREE_H
