import sort

array = [10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
length = 10

def printMenu():
    print('==================')
    print('1 - Print Array')
    print('2 - Scan Array')
    print('3 - Selection Sort')
    print('4 - Insertion Sort')
    print('5 - Bubble Sort')
    print('6 - Shell Sort')
    print('7 - Quick Sort')
    print('0 - Exit')
    print('==================')

def scanArray():
    for i in range(length):
        array[i] = int(input('Enter the value [' + str(i) + ']: '))
    return array

op = 1
while op:
    printMenu()
    op = int(input('Choose an option: '))

    if   op == 0: print('You chose to leave')
    elif op == 1: print(array)
    elif op == 2: print(scanArray())
    elif op == 3: print(sort.selectionSort(array))
    elif op == 4: print(sort.insertionSort(array))
    elif op == 5: print(sort.bubbleSort(array))
    elif op == 6: print(sort.shellSort(array))
    elif op == 7: print(sort.quickSort(array, 0, length - 1))
    else:         print('Please choose a valid option')
        