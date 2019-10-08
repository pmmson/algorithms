#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillArr(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		arr[i] = rand() % 100;
	}
}

void printArr(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int count = 0;

void bSort(int* arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++) {
			count++;
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void bSort2(int* arr, int len) {
	int k = len;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < len - 1; j++) {
			count++;
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				k = j + 1;
			}
			else
				k = j;
		}
	}
}

void shakerSort(int* arr, int len) {
	int min = 0;
	int max = len;
	int i = 0;
	int k;
	while (max > min) {
		k = 0;
		while (i < max - 1) {
			count++;
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
				k = 1;
			}
			i++;
		}
		if (k == 0) break;
		max = i;
		k = 0;
		while (i > min) {
			count++;
			if (arr[i] < arr[i - 1]) {
				swap(&arr[i], &arr[i - 1]);
				k = 1;
			}
			i--;
		}
		if (k == 0) break;
		min = i + 1;
	}
}

int main() {
	srand(time(NULL));

	int SIZE = 30;
	int arr[30];

	fillArr(arr, SIZE);
	printf("before:\n");
	printArr(arr, SIZE);
	bSort(arr, SIZE);
	printf("after:\n");
	printArr(arr, SIZE);
	printf("%d\n", count);

	fillArr(arr, SIZE);
	printf("before:\n");
	printArr(arr, SIZE);
	count = 0;
	bSort2(arr, SIZE);
	printf("after:\n");
	printArr(arr, SIZE);
	printf("%d\n", count);

	fillArr(arr, SIZE);
	printf("before:\n");
	printArr(arr, SIZE);
	count = 0;
	shakerSort(arr, SIZE);
	printf("after:\n");
	printArr(arr, SIZE);
	printf("%d\n", count);

	return 0;
}

