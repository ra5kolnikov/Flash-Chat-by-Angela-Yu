#include "rpn.h"

void preproc_str(char *str) {
    int is = 0;
    while ( is <= (int)strlen(str) - 1 ) {
        if (str[is] == '-' && is == 0) {
            str[is] = '~';
        } else if (str[is] == '-' && str[is-1] == '(') {
            str[is] = '~';
        }
        is++;
    }
}

void postpoc_srt(char *str) {
    for ( int i = 0 ; i <= (int)strlen(str) ; i++ )
        if ( (str[i] == ' ') && (str[i+1] == ' ') ) {
            for ( int j = i ; j <= (int)strlen(str) ; j++ )
                str[j] = str[j+1];
            i = i - 1;
    }
    str[strlen(str) - 1] = '\0';
}

char * str_to_rpn(char * str, char * res, struct node *head) {
    preproc_str(str);
    char result[100] = "";
    while ( *str ) {
    if ( is_digit(str) ) {
        double val;
        val = atof(str);
        while ( is_digit(str) || *str == '.' )
            str++;
        str--;
        char val_str[20];
        gcvt(val, 10, val_str);
        strcat(result, val_str);
    } else if ( *str == 'x' ) {
        strcat(result, "x");
    } else if ( *str == '(' ) {
        head = push(head, '(');
    } else if ( *str == ')' ) {
        while ( head->data != '(' ) {
            char op;
            head = pop(head, &op);
            if ( empty(head) != 0 )
                op = '\0';
            char ops[3] = {op, ' ', '\0'};
            strcat(result, ops);
        }
        char op;
        head = pop(head, &op);
    } else if ( *str == '+' || *str == '-' || *str == '*' || *str == '/' || *str == '^' ) {
        while ( empty(head) == 0 && prority(head->data) >= prority(*str) ) {
            char op;
            head = pop(head, &op);
            char ops[3] = {op, ' ', '\0'};
            strcat(result, ops);
        }
        head = push(head, *str);
    } else if ( *str == 's' || *str == 'c' || *str == 't' || *str == 'l' || *str == '~' ) {
        if ( *str == 'l' ) {
            head = push(head, 'l');
            str++;
        }
        if ( *str == 't' ) {
            head = push(head, 't');
            str += 2;
        }
        if ( *(str + 1) == 'i' ) {
            head = push(head, 's');
            str += 2;
        }
        if ( *(str + 1) == 'q' ) {
            head = push(head, 'q');
            str += 3;
        }
        if ( *(str + 1) == 'o' ) {
            head = push(head, 'c');
            str += 2;
        }
        if ( *(str + 1) == 't' ) {
            head = push(head, 'g');
            str += 2;
        }
        if ( *(str) == '~' ) {
            head = push(head, '~');
        }
    }
    str++;
    strcat(result, " ");
    }
    while ( empty(head) == 0 ) {
            char op;
            head = pop(head, &op);
            char ops[3] = {op, ' ', '\0'};
            strcat(result, ops);
    }
    strcat(res, result);
    postpoc_srt(res);
    return res;
}

int is_digit(const char *str) {
    int res = 0;
    if ( *str >= '0' && *str <= '9' )
        res = 1;
    return res;
}

int prority(char t) {
    int result = 0;
    if ( t == '(' )
        result = 1;
    if ( t == '+' || t == '-' )
        result  = 2;
    if ( t == '*' || t == '/' )
        result = 3;
    if ( t == '^' )
        result = 4;
    if ( t == 's' || t == 'c' || t == 't' || t == 'g' || t == 'q' || t == '~' )
        result = 6;
    return result;
}

int input(char *data) {
    int flag = 1;
    int i = 0;
    while (flag == 1) {
        scanf("%c", data + i);
        if (data[i] == '\n') {
            flag = 2;
            break;
        }
        i++;
    }
    return flag;
}
