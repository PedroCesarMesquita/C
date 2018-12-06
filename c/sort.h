void selectionSort(int *array, int length) {
	int i, j, min, aux;
	for(i = 0; i < length; i++) {
		min = i;
		for(j = i + 1; j < length; j++) {
			if(array[j] < array[min])
				min = j;
		}
		aux = array[i];
		array[i] = array[min];
		array[min] = aux;
	}
}

void insertionSort(int *array, int length) {
	int i, j, current;
	for(i = 1; i < length; i++) {
		current = array[i];
		for(j = i; j > 0 && current < array[j - 1]; j--)
			array[j] = array[j - 1];
		array[j] = current;
	}
}

void bubbleSort(int *array, int length) {
	int i, swapped, aux;
	do {
		swapped = 0;
		for(i = 1; i < length; i++) {
			if(array[i] < array[i - 1]) {
				aux = array[i];
				array[i] = array[i - 1];
				array[i - 1] = aux;
				swapped = 1;
			}
		}
	} while(swapped);
}

void shellSort(int *array, int length) {
	int i, j, aux, gap;
	for(gap = 1; gap < length / 3; gap = gap * 3 + 1);
	for(; gap; gap = (gap - 1) / 3)
		for(i = gap; i < length; i++) {
			for(j = i; j >= gap && array[j] < array[j - gap]; j -= gap) {
				aux = array[j];
				array[j] = array[j - gap];
				array[j - gap] = aux;
			}
		}
}

void quickSort(int *array, int lo, int hi) {
   	int pivot = lo, i, j, aux;
   	for(i = lo + 1; i <= hi; i++) {
		if(array[j = i] < array[pivot]) {
			aux = array[j];
			while(j > pivot)
				array[j] = array[--j];
			array[pivot++] = aux;
		}
	}
	if(pivot > lo + 1) quickSort(array, lo, pivot - 1);
	if(pivot < hi - 1) quickSort(array, pivot + 1, hi);
}