#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "conio.h"
#include "locale.h"
#include "arrays.h"

int main() {
	setlocale(LC_ALL, "Russian");
	int row, col;
	int** arr;
	printf("Введите количество строк массива:\n");
	input_arr_size(&row);
	printf("Введите количество элементов в строке массива:\n");
	input_arr_size(&col);
	arr_memory_allocate(row, col, &arr);
	input_arr(row, col, &arr);
	printf("Исходный массив:\n");
	output_arr(row, col, &arr);
	arr_job(&row, col, &arr);
	printf("Итоговый массив:\n");
	output_arr(row, col, &arr);
	arr_free(row, &arr);
}
