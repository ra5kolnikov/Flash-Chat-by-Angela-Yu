#include "stack_double.h"

struct noded* pushd(struct noded* head, double data) {
    struct noded* tmp = (struct noded*)malloc(sizeof(struct noded));
    tmp->data = data;
    tmp->next = head;
    return tmp;
}

struct noded * popd(struct noded *head, double *t) {
    *t = head->data;
    struct noded* tmp = head;
    head = head->next;
    free(tmp);
    return head;
}
