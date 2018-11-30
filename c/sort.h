void selectionSort(int *vetor, int tam) {
	int i, j, menor, troca;
	for(i = 0; i < tam; i++) {
		menor = i;
		for(j = i + 1; j < tam; j++) {
			if(vetor[j] < vetor[menor])
				menor = j;
		}
		troca = vetor[i];
		vetor[i] = vetor[menor];
		vetor[menor] = troca;
	}
}

void insertionSort(int *vetor, int tam) {
	int i, j, troca;
	for(i = 1; i < tam; i++)
		for(j = i; j > 0 && vetor[j] < vetor[j - 1]; j--) {
			troca = vetor[j];
            vetor[j] = vetor[j - 1];
            vetor[j - 1] = troca;
		}
}

void bubbleSort(int *vetor, int tam) {
	int i, ordenado, troca;
	do {
		ordenado = 1;
		for(i = 1; i < tam; i++) {
			if(vetor[i] < vetor[i - 1]) {
				troca = vetor[i];
				vetor[i] = vetor[i - 1];
				vetor[i - 1] = troca;
				ordenado = 0;
			}
		}
	} while(!ordenado);
}

void shellSort(int *vetor, int tam) {
	int i, j, n = tam, troca;
	while(n /= 2)
		for(i = n; i < tam; i += n) {
			for(j = i; j > 0 && vetor[j] < vetor[j - n]; j -= n) {
				troca = vetor[j];
				vetor[j] = vetor[j - n];
				vetor[j - n] = troca;
			}
		}
}

void quickSort(int *vetor, int esq, int dir) {
   	int pivo = esq, i, j, troca;
   	for(i = esq + 1; i <= dir; i++) {
		if(vetor[j = i] < vetor[pivo]) {
			troca = vetor[j];
			while(j > pivo)
				vetor[j] = vetor[--j];
			vetor[pivo++] = troca;
		}
	}
	if(pivo > esq + 1) quickSort(vetor, esq, pivo - 1);
	if(pivo < dir - 1) quickSort(vetor, pivo + 1, dir);
}