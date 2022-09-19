#ifndef SRC_STACK_CHAR_H_
#define SRC_STACK_CHAR_H_
#include <stdlib.h>

struct node {
    char data;
    struct node* next;
};

struct node* push(struct node* head, char data);
struct node * pop(struct node *head, char *t);
int empty(const struct node* head);

#endif  // SRC_STACK_CHAR_H_
