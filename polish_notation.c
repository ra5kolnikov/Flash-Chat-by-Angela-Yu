#include "calcPN.h"
#include "rpn.h"
#include "print_screen.h"

int main() {
    char inputStr[1000];
    char modifiedToRpn[1000];
    double rpnValues[W];
    struct node *head = NULL;
    input(inputStr);
    str_to_rpn(inputStr, modifiedToRpn, head);
    calc_res_massPN(modifiedToRpn, rpnValues);
    print_screen(rpnValues);
    return 0;
}
