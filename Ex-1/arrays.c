#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "malloc.h"
#include "locale.h"
#include "Arrays.h"

void check(int* k) {
    while (!scanf_s("%d", &*k) || *k <= 0 || getchar() != '\n') {
        printf("Проверьте корректность введенных данных!\n");
        rewind(stdin);
    }
}

void check_el(int* k) {
    while (!scanf_s("%d", &*k) || getchar() != '\n') {
        printf("Проверьте корректность введенных данных!\n");
        rewind(stdin);
    }
}

void fill_arr(int len, int** arr) {
    printf("Введите элементы массива:\n");
    for (int i = 0; i < len; i++) {
        printf("arr[%d] = ", i);
        check_el(&(*arr)[i]);
    }
}

void transform(int* len, int** arr) {
    for (int i = 0; i < (*len); i++) {
        if ((*arr)[i] == 0) {
        } else
        if ((*arr)[i] % 11 == 0 && i == (*len) - 1) {
            (*arr)[i] = 0;
            (*len)--;
            (*arr) = (int*)realloc((*arr), (*len) * sizeof(int));
        } else
            if ((*arr)[i] % 11 == 0) {
                for (int j = i; j < (*len) - 1; j++) {
                    (*arr)[j] = (*arr)[j + 1];
                }
                (*arr)[(*len) - 1] = 0;
                (*len)--;
                (*arr) = (int*)realloc((*arr), (*len) * sizeof(int));
                i--;
            }
    }
}

void output(int** arr, int len) {
    printf("\n"); printf("Массив:\n");
    for (int j = 0; j < len; j++) {
        printf("%d\t", (*arr)[j]);
    }
    printf("\n");
}

void arr_free(int** arr) {
    free((*arr));
}
