#include <stdio.h>
#define TAM 10

void imprimeMenu();
void imprimeVetor(int *);
void leVetor(int *);
void troca(int *, int *);
void ordenacaoSelecao(int *);
void ordenacaoInsercao(int *);
void ordenacaoBolha(int *);

int main() {
	int vetor[TAM] = {0};
	int op = 1;
	while(op) {
		imprimeMenu();
		scanf("%d", &op);
		switch(op) {
			case 1: imprimeVetor(vetor); break;
			case 2: leVetor(vetor); break;
			case 3: ordenacaoSelecao(vetor); break;
			case 4: ordenacaoInsercao(vetor); break;
			case 5: ordenacaoBolha(vetor); break;
		}
	}
	return 0;
}

void imprimeMenu() {
    puts("======================");
    puts("1 - Imprimir vetor");
    puts("2 - Preencher vetor");
    puts("3 - Ordenacao selecao");
    puts("4 - Ordenacao insercao");
    puts("5 - Ordenacao bolha");
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

void ordenacaoSelecao(int *vetor) { // Selection Sort
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

void ordenacaoInsercao(int *vetor) { // Insertion Sort
	int i, j;
	for(i = 1; i < TAM; i++)
		for(j = i; j > 0 && vetor[j] < vetor[j - 1]; j--) {
			troca(&vetor[j], &vetor[j - 1]);
		}
	puts("Ordenado com metodo Insercao");
}

void ordenacaoBolha(int *vetor) { // Bubble Sort
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
