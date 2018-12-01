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
    for(let i = 1; i < array.length; i++)
        for(let j = i; j > 0 && array[j] < array[j - 1]; j--) {
            const aux = array[j];
            array[j] = array[j - 1];
            array[j - 1] = aux;
        }
    return array;
}

const bubbleSort = array => {
    let ordered;
    do {
        ordered = true;
        for(let i = 1; i < array.length; i++) {
            if(array[i] < array[i - 1]) {
                const aux = array[i];
                array[i] = array[i - 1];
                array[i - 1] = aux;
                ordered = false;
            }
        }
    } while(!ordered);
    return array;
}

const quickSort = (array, left = 0, right = array.length - 1) => {
    let pivot = left;
    for(let i = left + 1; i <= right; i++) {
        if(array[i] < array[pivot]) {
            const aux = array[i];
            for(j = i; j > pivot; j--)
                array[j] = array[j - 1];
            array[pivot++] = aux;
        }
    }
    if(pivot > left + 1) quickSort(array, left, pivot - 1);
    if(pivot < right - 1) quickSort(array, pivot + 1, right);
}