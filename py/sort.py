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
        currentValue = array[i]
        j = i
        while j > 0 and currentValue < array[j - 1]:
            array[j] = array[j - 1]
            j -= 1
        array[j] = currentValue
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

def shellSort(array):
    gap = 1
    for i in range(len(array)):
        gap = gap * 3 + 1
    while gap > 0:
        for i in range(gap, len(array)):
            currentValue = array[i]
            j = i
            while j >= gap and currentValue < array[j - gap]:
                array[j] = array[j - gap]
                j -= gap
            array[j] = currentValue
        gap = int((gap - 1) / 3)
    return array