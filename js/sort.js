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

const doubleSelectionSort = (array) => {
    let left = 0, right = array.length - 1;
    while(left <= right) {
        let min = left, max = right;
        for(let i = left + 1; i <= right; i++)
            if(array[i] < array[min]) min = i;
        let aux = array[left];
        array[left] = array[min];
        array[min] = aux;
        for(let i = right - 1; i >= left; i--)
            if(array[i] > array[max]) max = i;
        aux = array[right];
        array[right] = array[max];
        array[max] = aux;
        left++;
        right--;
    }
}

const insertionSort = array => {
    for(let i = 1, j; i < array.length; i++) {
        let j, currentValue = array[i];
        for(j = i; j > 0 && currentValue < array[j - 1]; j--)
            array[j] = array[j - 1];
        array[j] = currentValue;
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

const shellSort = array => {
    let gap;
    for(gap = 1; gap < array.length / 3; gap = gap * 3 + 1);
    for(; gap; gap = (gap - 1) / 3)
        for(let i = gap; i < array.length; i++) {
            let j, currentValue = array[i];
            for(j = i; j >= gap && currentValue < array[j - gap]; j -= gap)
                array[j] = array[j - gap];
            array[j] = currentValue;
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
    return array;
}