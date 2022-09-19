#include "calcPN.h"
#include "print_screen.h"
#include <string.h>
#include <math.h>

int is_operation(char c) {
    int result = 0;
    switch (c) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
    case 's':  // sin
    case 'c':  // cos
    case 't':  // tan
    case 'g':  // ctg
    case 'q':  // sqrt
    case 'l':  // log
    case '~':
        result = 1;
        break;
    default:
        break;
    }
    return result;
}

int is_unary_operation(char d) {
    int res = 0;
    switch (d) {
    case 's':  // sin
    case 'c':  // cos
    case 't':  // tan
    case 'g':  // ctg
    case 'q':  // sqrt
    case 'l':  // log
    case '~':
        res = 1;
        break;
    default:
        break;
    }
    return res;
}

double calc_binary(char c, double first, double second) {
    double result = 0;
    switch (c) {
    case '+':
        result = first + second;
        break;
    case '-':
        result = first - second;
        break;
    case '*':
        result = first * second;
        break;
    case '/':
        result = first / second;
        break;
    case '^':
        result = pow(first, second);
        break;
    case 's':  // sin
        result = sin(second);
        break;
    case 'c':  // cos
        result = cos(second);
        break;
    case 't':  // tan
        result = tan(second);
        break;
    case 'g':  // ctg
        result = cos(second) / sin(second);
        break;
    case 'q':  // sqrt
        result = pow(second, 0.5);
        break;
    case 'l':  // log
        result = log(second);
        break;
    case '~':
        result = (-1.0) * second;
    default:
        break;
    }
    return result;
}

int is_digit_double(char c) {
    return ('0' <= c && c <= '9') || (c == 'x') || (c == '.');
}

double str_to_double(char *postfixPN, int *ptr) {
    int cnt = 0;
    double d = atof(postfixPN + *ptr);
    while (postfixPN[*ptr] != ' ') {
        if (is_digit_double(postfixPN[*ptr])) {
            cnt++;
        }
        *ptr += 1;
    }
    return d;
}

double calc_result(char *postfixPN, double x) {
    struct noded *d = 0;
    double result = 0;
    for (int i = 0; i < (int)strlen(postfixPN); i++) {
        char symbol = postfixPN[i];
        if (symbol == 'x') {
            d = pushd(d, x);
        } else {
            if (is_digit_double(symbol)) {
                double a = str_to_double(postfixPN, &i);
                d = pushd(d, a);
            } else {
                if (is_operation(symbol)) {
                    if (is_unary_operation(symbol)) {
                        double second = 0;
                        d = popd(d, &second);
                        d = pushd(d, calc_binary(symbol, 0, second));
                    } else {
                        double first = 0;
                        double second = 0;
                        d = popd(d, &second);
                        d = popd(d, &first);
                        double res = calc_binary(symbol, first, second);
                        d = pushd(d, res);
                    }
                }
            }
        }
    }
    popd(d, &result);
    return result;
}

void calc_res_massPN(char *str, double *mass) {
    for (int i = 0; i < W; i++) {
        mass[i] = calc_result(str, (double)i * (4. * M_PI) / 79.);
    }
    function_for_print(mass);
}
