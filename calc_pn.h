#ifndef SRC_CALCPN_H_
#define SRC_CALCPN_H_
#include "stack_double.h"

double calc_binary(char c, double first, double second);
int is_digit_double(char c);
double str_to_double(char *postfixPN, int *ptr);
double calc_result(char *postfixPN, double x);
int is_operation(char c);
int is_unary_operation(char d);
void calc_res_massPN(char *str, double *mass);


#endif  // SRC_CALCPN_H_
