//
// Created by LIRUIBO on 24-3-17.
//
#include "stdio.h"
#include "Node.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
extern int yylineno;
int has_error = 0;
node create_node(char* name, int line, int child_num, node* childlist) {
    node new_node = malloc(sizeof(struct tree_node));
    if (!new_node) {
        return NULL;
    }
    new_node->name = name;
    new_node->child_num = child_num;
    new_node->child = childlist;
    new_node->line = line;
    new_node->literal = NULL; 
    new_node->literal_type = TYPE_NULL;
    if(child_num>0){
        new_node->line = get_line(new_node);
    }
    return new_node;
}
int get_line(node node){
    if(node->line != 0){
        return node->line;
    }
    for(int i = 0; i < node->child_num ; i++){
        return get_line(node->child[i]);
    }
}
void set_literal(node node, ValueType type, void* value) {
    if (node->literal) {
        free(node->literal);
    }
    node->literal_type = type;
    switch (type) {
        case TYPE_INT:
            node->literal = malloc(sizeof(int));
            if (!node->literal) {
                return;
            }
            *(int*)node->literal = my_stoi(value);
            break;
        case TYPE_ID:
            node->literal = malloc(strlen((char*)value) + 1);
            if (!node->literal) {
                return;
            }
            strcpy((char*)node->literal, (char*)value);
            break;
        case TYPE_FLOAT:
            node->literal = malloc(sizeof(float));
            if (!node->literal) {
                return;
            }
            *(float*)node->literal = my_stof(value);
            break;
    }
}

node* create_child_list(int num_children, node children[]) {
    node* child_list = malloc(num_children * sizeof(node));
    if (!child_list) {
        printf("malloc error");
        return NULL;
    }
    for (int i = 0; i < num_children; ++i) {
        child_list[i] = children[i];
    }
    return child_list;
}

void print_tree(node head, int depth) {
    if(has_error != 0){
        return;
    }
    if(!head || !strcmp(head->name,"NULL")){
        return;
    }
    for (int i = 0; i < depth; ++i) {
        printf("  ");
    }
    if (head->child_num != 0){
        printf("%s (%d)", head->name, head->line);
    }
    else{
        printf("%s ", head->name);
    }
    if (head->literal != NULL) {
        if (strcmp(head->name, "INT") == 0) {
            printf(": %d", *((int*)head->literal));
        } else if (strcmp(head->name, "FLOAT") == 0) {
            printf(": %f", *((float*)head->literal));
        } else if (strcmp(head->name, "ID") == 0 || strcmp(head->name,"TYPE") == 0) {
            printf(": %s", (char*)head->literal);
        }
        printf("\n");
        return;
    }
    printf("\n");
    for (int i = 0; i < head->child_num; ++i) {
        print_tree(head->child[i], depth+1);
    }
}
int my_stoi(char *value) {
    int result = 0; 
    int base = 10; 
    int sign = 1;  

    if (*value == '-' || *value == '+') {
        sign = (*value == '-') ? -1 : 1;
        value++; 
    }

    if (strncmp(value, "0X", 2) == 0 || strncmp(value, "0x", 2) == 0) {
        base = 16;
        value += 2; 
    } else if (*value == '0') {
        base = 8;
        value++; 
    }

    switch (base) {
        case 10: 
            while (*value) {
                if (*value < '0' || *value > '9') {
                    return 0;
                }
                result = result * 10 + (*value - '0');
                value++;
            }
            break;
        case 8: 
            while (*value) {
                if (*value < '0' || *value > '7') {
                    return 0;
                }
                result = result * 8 + (*value - '0');
                value++;
            }
            break;
        case 16:
            while (*value) {
                if ((*value >= '0' && *value <= '9') || 
                    (*value >= 'a' && *value <= 'f') || 
                    (*value >= 'A' && *value <= 'F')) {
                    result = result * 16 + (isdigit(*value) ? *value - '0' : tolower(*value) - 'a' + 10);
                } else {
                    return 0;
                }
                value++;
            }
            break;
        default:
            return 0;
    }

    return sign * result;
}
float my_stof(char *value) {
    float result = 0; 
    int sign = 1;      
    float decimal = 1; 
    float exponent = 0; 

    if (*value == '-' || *value == '+') {
        sign = (*value == '-') ? -1 : 1;
        value++; 
    }

    while (isdigit(*value)) {
        result = result * 10 + (*value - '0');
        value++;
    }

    if (*value == '.') {
        value++; 
        while (isdigit(*value)) {
            result = result * 10 + (*value - '0');
            decimal *= 10;
            value++;
        }
    }

    if (*value == 'e' || *value == 'E') {
        value++; 
        int expSign = 1;
        if (*value == '-' || *value == '+') {
            expSign = (*value == '-') ? -1 : 1;
            value++; 
        }
        while (isdigit(*value)) {
            exponent = exponent * 10 + (*value - '0');
            value++;
        }
        exponent *= expSign;
    }

    result = sign * result / decimal;
    if (exponent != 0) {
        result = result * pow(10, exponent);
    }

    return result;
}

void error_A(int line,char* character, char * msg){
    has_error = 1;
    if(msg != NULL){
        printf("Error type A at Line %d: %s \'%s\'\n",line, msg, character);
    }
    else{
        printf("Error type A at Line %d: Mysterious characters \'%s\'\n",line, character);
    }
    
}
void yyerror(char *msg){
    has_error = 1;
    fprintf(stderr, "Error type B at Line %d: %s.\n", yylineno, msg);
}