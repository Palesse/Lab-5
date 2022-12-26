#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
#include "conio.h"
#include "arrays.h"

void check(int* k) {
	while (scanf_s("%d", &*k) != 1 || *k <= 0 || getchar() != '\n') {
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

void input_arr(int row, int*** arr) {
	for (int i = 0; i < row; i++) {
		int j = 0;
		while (printf("arr[%d][%d] = ", i, j), scanf_s("%d", &(*arr)[i][j]) != 0 && (*arr)[i][j] != 0) {
			(*arr)[i] = (int*)realloc((*arr)[i], (j + 2) * sizeof(int));
			j++;
		}

	}
}

void output_arr(int row, int*** arr) {
	for (int i = 0; i < row; i++) {
		int j = 0;
		while ((*arr)[i][j] != 0) {
			printf("%d\t", (*arr)[i][j]);
			j++;
			if ((*arr)[i][j] == 0) {
				printf("\n");
			}
		}
	}
}

void arr_job(int row, int*** arr) {
	for (int i = 0; i < row; i++) {
		int col = 0; int max_elem = (*arr)[i][0];
		int j = 0;
		while ((*arr)[i][j]) {
			col++;
			j++;
		}
		col++; 
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] > max_elem) {
				max_elem = (*arr)[i][j];
			}
		}
		for (int j = 0; j < col; j++) {
			if ((*arr)[i][j] == max_elem) {
				col--;
				for (int k = j; k < col; k++) {
					(*arr)[i][k] = (*arr)[i][k + 1];
				}
				j--;
				(*arr)[i] = (int*)realloc((*arr)[i], col * sizeof(int));
			}
		}
	}
}

void arr_free(int row, int*** arr) {
	for (int j = 0; j < row; j++) {
		free(*(arr + j));
	}
	free(arr);
}
