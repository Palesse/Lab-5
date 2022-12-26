#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "locale.h"
#include "arrays.h"
#include "string.h"

int main(void) {
    setlocale(LC_ALL, "Russian");
    int len;
    printf("Введите количество элементов матрицы:\n");
    check(&len);
    int* arr = (int*)malloc(len * sizeof(int));
    fill_arr(len, &arr);
    printf("Исходный массив:\n");
    output(&arr, len);
    transform(&len, &arr);
    printf("Итоговый массив:\n");
    output(&arr, len);
    arr_free(&arr);
}
