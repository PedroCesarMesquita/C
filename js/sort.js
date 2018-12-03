const selectionSort = array => {
    for(let i = 0; i < array.length; i++) {
        let min = i;
        for(let j = i + 1; j < array.length; j++) {
            if(array[j] < array[min])
                min = j;
        }
        const aux = array[i];
        array[i] = array[min];
        array[min] = aux;
    }
    return array;
}

const insertionSort = array => {
    for(let i = 1, j; i < array.length; i++) {
        let j, current = array[i];
        for(j = i; j > 0 && current < array[j - 1]; j--)
            array[j] = array[j - 1];
        array[j] = current;
    }
    return array;
}

const bubbleSort = array => {
    let swapped;
    do {
        swapped = false;
        for(let i = 1; i < array.length; i++) {
            if(array[i] < array[i - 1]) {
                const aux = array[i];
                array[i] = array[i - 1];
                array[i - 1] = aux;
                swapped = true;
            }
        }
    } while(swapped);
    return array;
}

const shellSort = (array) => {
    let gaps = new Array(array.length);
    gaps[array.length - 1] = 1;
    for(let i = array.length - 2; i >= 0; i--)
        gaps[i] = gaps[i + 1] * 3 + 1;
    for(gap of gaps) {
        for(let i = gap; i < array.length; i++) {
            for(let j = i; j >= gap && array[j] < array[j - gap]; j -= gap) {
                const aux = array[j];
                array[j] = array[j - gap];
                array[j - gap] = aux;
            }
        }
    }
    return array;
}

const quickSort = (array, lo = 0, hi = array.length - 1) => {
    let pivot = lo;
    for(let i = lo + 1; i <= hi; i++) {
        if(array[i] < array[pivot]) {
            const aux = array[i];
            for(j = i; j > pivot; j--)
                array[j] = array[j - 1];
            array[pivot++] = aux;
        }
    }
    if(pivot > lo + 1) quickSort(array, lo, pivot - 1);
    if(pivot < hi - 1) quickSort(array, pivot + 1, hi);
}
