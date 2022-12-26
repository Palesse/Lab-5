#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "conio.h"
#include "arrays.h"

void input_arr_size(int* arr_size) {
	while (scanf_s("%d", arr_size) != 1 || arr_size <= 0 || getchar() != '\n') {
		printf("Проверьте корректность введенных данных!\n");
		rewind(stdin);
	}
}

void arr_memory_allocate(int row, int col, int*** arr) {
	*arr = (int**)malloc(row * sizeof(int*));
	for (int i = 0; i < row; i++) {
		(*arr)[i] = (int*)calloc(col, sizeof(int));
	}
}

void input_arr(int row, int col, int*** arr) {
	printf("Введите элементы массива:\n");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("arr[%d][%d] = ", i, j);
			while (scanf_s("%d", &(*arr)[i][j]) != 1 || getchar() != '\n') {
				printf("Проверьте корректность введенных данных!\n");
				rewind(stdin);
			}
			printf("\n");
		}
	}
}

void output_arr(int row, int col, int*** arr) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", (*arr)[i][j]);
		}
		printf("\n");
	}
}

void arr_job(int* row, int col, int*** arr) {
	int two_zero;
	for (int i = 0; i < (*row); i++) {
		two_zero = 0;
		int j = 0;
		while (two_zero == 0 && j < (col - 1)) {
			if ((*arr)[i][j] == 0 && (*arr)[i][j + 1] == 0) {
				two_zero = 1;
			}
			else {
				j++;
			}
		}
		if (two_zero == 1 && i == (*row) - 1) {
			for (int j = 0; j < col; j++) {
				(*arr)[i][j] = 0;
			}
			(*row)--;
			(*arr) = (int**)realloc((*arr), (*row) * sizeof(int*));
			i--;
		} else if (two_zero == 1) {
			for (int p = i; p < (*row) - 1; p++) {
				for (int j = 0; j < col; j++) {
					(*arr)[p][j] = (*arr)[p + 1][j];
				}
			}
			(*row)--;
			(*arr) = (int**)realloc((*arr), (*row) * sizeof(int*));
			i--;
		}
	 }
}

void arr_free(int row, int*** arr) {
	for (int i = 0; i < row; i++) {
		free((*arr)[i]);
	}
	free(*arr);
}
