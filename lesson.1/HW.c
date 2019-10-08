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
	int k = 0;
	while (max > min) {
		while (i < max - 1) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
			}
			i++;
		}
		printArr(arr, len);
		max = i;
		printf("\nmax: %d\n", max);
		while (i > min) {
			if (arr[i] < arr[i - 1]) {
				swap(&arr[i], &arr[i - 1]);
			}
			i--;
		}
		printArr(arr, len);
		min = i + 1;
		printf("\nmin: %d\n", min);
	}
}

int main() {
	srand(time(NULL));

	int SIZE = 7;
	int arr[7];
	fillArr(arr, SIZE);
	printArr(arr, SIZE);
	bSort(arr, SIZE);
	printArr(arr, SIZE);
	printf("%d\n", count);

	fillArr(arr, SIZE);
	printArr(arr, SIZE);
	count = 0;
	bSort2(arr, SIZE);
	printArr(arr, SIZE);
	printf("%d\n", count);

	fillArr(arr, SIZE);
	printArr(arr, SIZE);
	count = 0;
	shakerSort(arr, SIZE);
	printArr(arr, SIZE);
	printf("%d\n", count);

	return 0;
}

