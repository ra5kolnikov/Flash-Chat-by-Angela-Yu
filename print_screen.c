#include "print_screen.h"

void function_for_print(double y[W]) {
    for (int i = 0; i < W; i++) {
        y[i] = round(y[i] * (H - 1));
    }
}

void print_screen(const double y[W]) {
    char point = '*';
    char field = '.';
    for (int i = -(H - 1); i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == y[j]) {
                printf("%c", point);
            } else {
                printf("%c", field);
            }
        }
    printf("\n");
    }
}
