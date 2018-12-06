def selectionSort(array):
    length = len(array)
    for i in range(0, length):
        minor = i
        for j in range(i + 1, length):
            if array[j] < array[minor]:
                minor = j
        aux = array[i]
        array[i] = array[minor]
        array[minor] = aux
    return array

def insertionSort(array):
    length = len(array)
    for i in range(1, length):
        currentValue = array[i]
        j = i
        while j > 0 and currentValue < array[j - 1]:
            array[j] = array[j - 1]
            j -= 1
        array[j] = currentValue
    return array

def bubbleSort(array):
    length = len(array)
    swapped = 1
    while swapped:
        swapped = 0
        for i in range(1, length):
            if array[i] < array[i - 1]:
                aux = array[i]
                array[i] = array[i - 1]
                array[i - 1] = aux
                swapped = 1
    return array

def shellSort(array):
    length = len(array)
    gap = 1
    while gap < length / 3: gap = gap * 3 + 1
    while gap:
        for i in range(gap, length):
            currentValue = array[i]
            j = i
            while j >= gap and currentValue < array[j - gap]:
                array[j] = array[j - gap]
                j -= gap
            array[j] = currentValue
        gap = int((gap - 1) / 3)
    return array

def quickSort(array, lo, hi):
    pivot = lo
    for i in range(lo + 1, hi + 1):
        if(array[i] < array[pivot]):
            aux = array[i]
            j = i
            while j > pivot:
                array[j] = array[j - 1]
                j -= 1
            array[pivot] = aux
            pivot += 1
    if pivot > lo + 1: quickSort(array, lo, pivot - 1)
    if pivot < hi - 1: quickSort(array, pivot + 1, hi)
    return array