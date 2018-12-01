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