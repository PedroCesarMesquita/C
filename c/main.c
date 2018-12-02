#include <stdio.h>
#include "sort.h"

void printMenu();
void printArray(int *, int);
void scanArray(int *, int);

int main() {
	const int length = 20;
	int array[20] = {7, 1, 14, 3, 5, 4, 13, 8, 9, 11, 17, 18, 6, 15, 12, 2, 20, 19, 16, 10};
	int op;
	do {
		printMenu();
		scanf("%d", &op);
		switch(op) {
			case 0: puts("You chose to leave"); break;
			case 1: printArray(array, length); break;
			case 2: scanArray(array, length); break;
			case 3: selectionSort(array, length); break;
			case 4: insertionSort(array, length); break;
			case 5: bubbleSort(array, length); break;
			case 6: shellSort(array, length); break;
			case 7: quickSort(array, 0, length - 1); break;
			default: puts("Please enter a valid option"); break;
		}
		if(op >= 2 && op <= 7) printArray(array, length);
	} while(op);
	return 0;
}

void printMenu() {
	puts("======================");
	puts("1 - Print array");
	puts("2 - Fill array");
	puts("3 - Selection Sort");
	puts("4 - Insertion Sort");
	puts("5 - Bubble Sort");
	puts("6 - Shell Sort");
	puts("7 - Quick Sort");
	puts("0 - Exit");
	puts("======================");
	printf("Choose an option: ");
}

void printArray(int *array, int length) {
	int i;
	printf("======================\nArray\n%d", array[0]);
	for(i = 1; i < length; i++)
		printf(" %d", array[i]);
	putchar('\n');
}

void scanArray(int *array, int length) {
	int i;
	for(i = 0; i < length; i++) {
		printf("Enter the value [%d]: ", i);
		scanf("%d", &array[i]);
	}
}