#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "conio.h"
#include "locale.h"
#include "arrays.h"

int main() {
	setlocale(LC_ALL, "Russian");
	int row;
	printf("Введите количество строк в массиве:\n");
	check(&row);
	int** arr;
	arr_memory_allocate(row, 1, &arr);
	input_arr(row, &arr);
	printf("Исходный массив:\n");
	output_arr(row, &arr);
	arr_job(row, &arr);
	printf("Финальный массив:\n");
	output_arr(row, &arr);
	arr_free(row, &arr);
}
