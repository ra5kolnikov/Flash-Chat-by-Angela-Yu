#ifndef SRC_RPN_H_
#define SRC_RPN_H_
#include <stdio.h>
#include <string.h>
#include "stack_char.h"

void preproc_str(char *str);
void postpoc_srt(char *str);
char * str_to_rpn(char * str, char * res, struct node *stack);
int is_digit(const char *str);
int prority(char t);
int input(char *data);

#endif  // SRC_RPN_H_
