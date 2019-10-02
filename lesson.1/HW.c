#include <stdio.h>
#include <stdlib.h>


void decToBin(int n) {
	int ostatok = n % 2;
	if (n != 0) {
		n /= 2;
		decToBin(n);
		printf("%d", ostatok);
	}
}

int z;

int myPow1(int a, int b) {
	int result = 1;
	while (b != 0) {
		z++;
		result *= a;
		b--;
	}
	return result;
}

int myPow2(int a, int b) {
	z++;
	if (b != 0) {
		return a * myPow2(a, b - 1);
	}
	else return 1;
}

int myPow3(int a, int b) {
	z++;
	if (b != 0) {
		if (b % 2 == 0) {
			b /= 2;
			a *= a;
			myPow3(a, b);
		}
		else {
			return a * myPow3(a, b - 1);
		}
	}
	else return 1;
}


int main() {

	/* Task 1 */
	printf("\nDEC to BIN");
	for (int i = 1; i <= 15; i++) {
		printf("\n%d\t: ", i);
		decToBin(i);
	}
	printf("\n\n");
	/* end Task 1 */
	/* Task 2 */
	int a = 2;
	int b = 21;
	z = 0;
	printf("Simple Power       : %d\n", myPow1(a, b));
	printf("%d\n", z);
	z = 0;
	printf("Recurse Power      : %d\n", myPow2(a, b));
	printf("%d\n", z);
	z = 0;
	printf("Force Recurse Power: %d\n", myPow3(a, b));
	printf("%d\n", z);
	/* end Task 2 */

	return 0;
}

