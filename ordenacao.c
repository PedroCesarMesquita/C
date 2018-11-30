#include <stdio.h>

void imprimeMenu();
void imprimeVetor(int *, int);
void leVetor(int *, int);
void troca(int *, int *);
void selectionSort(int *, int);
void insertionSort(int *, int);
void bubbleSort(int *, int);
void shellSort(int *, int);
void quickSort(int *, int , int);

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

void troca(int *elemento1, int *elemento2) {
	int aux = *elemento1;
	*elemento1 = *elemento2;
	*elemento2 = aux;
}

void selectionSort(int *vetor, int tam) {
	int i, j, menor;
	for(i = 0; i < tam; i++) {
		menor = i;
		for(j = i + 1; j < tam; j++) {
			if(vetor[j] < vetor[menor])
				menor = j;
		}
		troca(&vetor[i], &vetor[menor]);
	}
}

void insertionSort(int *vetor, int tam) {
	int i, j;
	for(i = 1; i < tam; i++)
		for(j = i; j > 0 && vetor[j] < vetor[j - 1]; j--) {
			troca(&vetor[j], &vetor[j - 1]);
		}
}

void bubbleSort(int *vetor, int tam) {
	int i, ordenado;
	do {
		ordenado = 1;
		for(i = 1; i < tam; i++) {
			if(vetor[i] < vetor[i - 1]) {
				troca(&vetor[i], &vetor[i - 1]);
				ordenado = 0;
			}
		}
	} while(!ordenado);
}

void shellSort(int *vetor, int tam) {
	int i, j, n = tam;
	while(n /= 2)
		for(i = n; i < tam; i += n) {
			for(j = i; j > 0 && vetor[j] < vetor[j - n]; j -= n) {
				troca(&vetor[j], &vetor[j - n]);
			}
		}
}

void quickSort(int *vetor, int esq, int dir) {
   	int pivo = esq, i, j, aux;
   	for(i = esq + 1; i <= dir; i++) {
		if(vetor[j = i] < vetor[pivo]) {
			aux = vetor[j];
			while(j > pivo)
				vetor[j] = vetor[--j];
			vetor[pivo++] = aux;
		}
	}
	if(pivo > esq + 1) quickSort(vetor, esq, pivo - 1);
	if(pivo < dir - 1) quickSort(vetor, pivo + 1, dir);
}