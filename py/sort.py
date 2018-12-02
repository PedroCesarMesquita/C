def selectionSort(array):
    for i in range(0, len(array)):
        minor = i
        for j in range(i + 1, len(array)):
            if array[j] < array[minor]:
                minor = j
        aux = array[i]
        array[i] = array[minor]
        array[minor] = aux
    return array

def insertionSort(array):
    for i in range(1, len(array)):
        current = array[i]
        j = i
        while j > 0 and current < array[j - 1]:
            array[j] = array[j - 1]
            j -= 1
        array[j] = current
    return array

def bubbleSort(array):
    swapped = 1
    while swapped:
        swapped = 0
        for i in range(1, len(array)):
            if array[i] < array[i - 1]:
                aux = array[i]
                array[i] = array[i - 1]
                array[i - 1] = aux
                swapped = 1
    return array
