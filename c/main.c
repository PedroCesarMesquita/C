#include <stdio.h>
#include "sort.h"

void imprimeMenu();
void imprimeVetor(int *, int);
void leVetor(int *, int);

int main() {
	const int tam = 20;
	int vetor[20] = {7, 1, 14, 3, 5, 4, 13, 8, 9, 11, 17, 18, 6, 15, 12, 2, 20, 19, 16, 10};
	int op = 1;
	while(op) {
		imprimeMenu();
		scanf("%d", &op);
		switch(op) {
			case 0: puts("Voce escolheu sair"); break;
			case 1: imprimeVetor(vetor, tam); break;
			case 2: leVetor(vetor, tam); break;
			case 3: selectionSort(vetor, tam); break;
			case 4: insertionSort(vetor, tam); break;
			case 5: bubbleSort(vetor, tam); break;
			case 6: shellSort(vetor, tam); break;
			case 7: quickSort(vetor, 0, tam - 1); break;
			default: puts("Digite uma opcao valida"); break;
		}
		if(op >= 2 && op <= 7) imprimeVetor(vetor, tam);
	}
	return 0;
}

void imprimeMenu() {
	puts("======================");
	puts("1 - Imprimir vetor");
	puts("2 - Preencher vetor");
	puts("3 - Selection Sort");
	puts("4 - Insertion Sort");
	puts("5 - Bubble Sort");
	puts("6 - Shell Sort");
	puts("7 - Quick Sort");
	puts("0 - Sair");
	puts("======================");
	printf("Selecione a opcao: ");
}

void imprimeVetor(int *vetor, int tam) {
	int i;
	printf("======================\nVetor\n%d", vetor[0]);
	for(i = 1; i < tam; i++)
		printf(" %d", vetor[i]);
	putchar('\n');
}

void leVetor(int *vetor, int tam) {
	int i;
	for(i = 0; i < tam; i++) {
		printf("Digite o valor [%d]: ", i);
		scanf("%d", &vetor[i]);
	}
}