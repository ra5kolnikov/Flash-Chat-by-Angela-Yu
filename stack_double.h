#ifndef SRC_STACK_DOUBLE_H_
#define SRC_STACK_DOUBLE_H_
#include <stdlib.h>

struct noded {
    double data;
    struct noded* next;
};

struct noded* pushd(struct noded* head, double data);
struct noded* popd(struct noded *head, double *t);

#endif  // SRC_STACK_DOUBLE_H_
