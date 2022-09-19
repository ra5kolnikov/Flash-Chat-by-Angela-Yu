#include "stack_char.h"

struct node* push(struct node* head, char data) {
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->data = data;
    tmp->next = head;
    return tmp;
}

struct node * pop(struct node *head, char *t) {
    *t = head->data;
    struct node* tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

int empty(const struct node* head) {
    return head == NULL ? 1 : 0;
}
