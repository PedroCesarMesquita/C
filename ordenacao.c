#include <stdio.h>
#define TAM 10

void imprimeMenu();
void imprimeVetor(int *);
void leVetor(int *);
void troca(int *, int *);
void selectionSort(int *);
void insertionSort(int *);
void bubbleSort(int *);
void shellSort(int *);

int main() {
	int vetor[TAM] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int op = 1;
	while(op) {
		imprimeMenu();
		scanf("%d", &op);
		switch(op) {
			case 1: imprimeVetor(vetor); break;
			case 2: leVetor(vetor); break;
			case 3: selectionSort(vetor); break;
			case 4: insertionSort(vetor); break;
			case 5: bubbleSort(vetor); break;
			case 6: shellSort(vetor); break;
		}
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
    puts("0 - Sair");
    puts("======================");
	printf("Selecione a opcao: ");
}

void imprimeVetor(int *vetor) {
	int i;
	printf("======================\nVetor\n%d", vetor[0]);
	for(i = 1; i < TAM; i++)
		printf(" %d", vetor[i]);
	putchar('\n');
}

void leVetor(int *vetor) {
	int i;
	for(i = 0; i < TAM; i++) {
		printf("Digite o valor [%d]: ", i);
		scanf("%d", &vetor[i]);
	}
}

void troca(int *elemento1, int *elemento2) {
	int aux = *elemento1;
	*elemento1 = *elemento2;
	*elemento2 = aux;
}

void selectionSort(int *vetor) {
	int i, j, menor;
	for(i = 0; i < TAM; i++) {
		menor = i;
		for(j = i + 1; j < TAM; j++) {
			if(vetor[j] < vetor[menor])
				menor = j;
		}
		troca(&vetor[i], &vetor[menor]);
	}
	puts("Ordenado com metodo Selecao");
}

void insertionSort(int *vetor) {
	int i, j;
	for(i = 1; i < TAM; i++)
		for(j = i; j > 0 && vetor[j] < vetor[j - 1]; j--) {
			troca(&vetor[j], &vetor[j - 1]);
		}
	puts("Ordenado com metodo Insercao");
}

void bubbleSort(int *vetor) {
	int i, ordenado;
	do {
		ordenado = 1;
		for(i = 1; i < TAM; i++) {
			if(vetor[i] < vetor[i - 1]) {
				troca(&vetor[i], &vetor[i - 1]);
				ordenado = 0;
			}
		}
	} while(!ordenado);
	puts("Ordenado com metodo Bolha");
}

void shellSort(int *vetor) {
    int i, j, n = TAM;
	while(n /= 2)
    	for(i = n; i < TAM; i += n) {
    		for(j = i; j > 0 && vetor[j] < vetor[j - n]; j -= n) {
    			troca(&vetor[j], &vetor[j - n]);
    		}
    	}
    puts("Ordenado com metodo Shell");
}
