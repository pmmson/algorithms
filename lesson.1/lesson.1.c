#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float bodyMassIndex(int m, float h) {
	return m / (h * h);
}

void swap(int* a, int* b) {
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

int sqrtSolution(int a, int b, int c, float* x1, float* x2) {
	float d = b * b - 4 * a * c;
	if (a != 0) {
		if (d > 0) {
			*x1 = (-b - sqrt(d)) / (2 * a);
			*x2 = (-b + sqrt(d)) / (2 * a);
			return 2;
		}
		else if (d == 0) {
			*x1 = -b / (2 * a);
			return 1;
		}
		else {
			return 0;
		}
	}
	else {
		*x1 = -c / (float)b;
		return -1;
	}
}

ages(int age) {
	int i = age % 10;
	int j = (age / 10) % 10;
	if ((i >= 2 && i <= 4) && j != 1) {
		printf("%d goda\n", age);
	}
	else if (i == 1 && j != 1) {
		printf("%d god\n", age);
	}
	else {
		printf("%d let\n", age);
	}
}

void isHaveOddN(int n) {
	while (n != 0) {
		if ((n % 10) % 2 != 0) {
			printf("true\n");
			break;
		}
		else {
			n = n / 10;
			if (n == 0) {
				printf("false\n");
			}
		}
	}
}

void divNumbers(int x, int y) {
	int a = x;
	int b = y;
	int c = 0;
	while (x >= y) {
		x = x - y;
		c++;
	}
	if (x == 0) {
		printf("%d / %d = result: %d\n", a, b, c);
	}
	else {
		printf("%d / %d = result: %d, ostatok: %d\n", a, b, c, x);
	}
}

float mean() {
	int sum = 0;
	int counter = 0;
	int in;
	
	/*
	// before:
	scanf("%d", &in);

	while (in != -1) {
		sum = sum + in;
		counter++;
		scanf("%d", &in);
	}
	*/

	while (1) {
		scanf("%d", &in);
		if (in != -1) {
			sum = sum + in;
			counter++;
		}
		else {
			break;
		}
	}

	if (counter != 0) {
		return (float)sum / counter;
	}
	else {
		return -1;
	}
}


int main() {
	/*
	1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);
	где m-масса тела в килограммах, h - рост в метрах.
	*/
	int m;
	printf("Input weight: ");
	scanf("%d", &m);
	float h;
	printf("Input hight(m): ");
	scanf("%f", &h);
	printf("BMI = %.2f\n", bodyMassIndex(m, h));

	printf("====================\n");
	/*
	3. Написать программу обмена значениями двух целочисленных переменных: b. *без использования третьей переменной.
	*/
	int k = 5;
	int l = 3;
	printf("k: %d | l: %d\n", k, l);
	swap(&k, &l);
	printf("k: %d | l: %d\n", k, l);

	printf("====================\n");
	/*
	4. Написать программу нахождения корней заданного квадратного уравнения.
	*/
	int a, b, c;
	float x1, x2;
	printf("Input sqrt: a b c\n");
	scanf("%d %d %d", &a, &b, &c);
	printf("(%d)x(2)+(%d)x+(%d)=0\n", a, b, c);
	int result = sqrtSolution(a, b, c, &x1, &x2);
	switch (result) {
	case 2:
		printf("Solution: x1=%.2f; x2=%.2f\n", x1, x2);
		break;
	case 1:
		printf("Solution: x1=%.2f\n", x1);
		break;
	case 0:
		printf("No solution!\n");
		break;
	case -1:
		printf("No sqrt! Solution: x1=%.2f\n", x1);
		break;
	}

	printf("====================\n");
	/*
	6. Ввести возраст человека (от 1 до 150 лет) и вывести его вместе с последующим словом «год», «года» или «лет»
	*/
	int age;
	printf("Input age (1...150): ");
	scanf("%d", &age);
	ages(age);
	
	printf("====================\n");
	/*
	10. Дано целое число N (> 0).
	С помощью операций деления нацело и взятия остатка от деления определить,
	имеются ли в записи числа N нечетные цифры. Если имеются, то вывести True, если нет — вывести False
	*/
	printf("Input N: ");
	int n;
	scanf("%d", &n);
	isHaveOddN(n);

	printf("====================\n");
	/*
	9. Даны целые положительные числа N и K.
	Используя только операции сложения и вычитания, найти частное от деления нацело N на K,
	а также остаток от этого деления
	*/
	divNumbers(13, 3);
	divNumbers(20, 5);
	divNumbers(117, 4);

	printf("====================\n");
	/*
	15. Дублирую задание по улучшению алгоритма с урока))
	*/
	printf("%f\n", mean());

	printf("====================\n");


	return 0;
}

