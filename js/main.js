const randomArray = (length = 50) => {
    let array = [], availableNumbers = [];
    for(let i = 0; i < length; i++)
        availableNumbers.push(i + 1);
    for(let i = 0; i < length; i++) {
        const randomIndex = Math.floor(Math.random() * availableNumbers.length);
        array.push(availableNumbers[randomIndex]);
        availableNumbers.splice(randomIndex, 1);
    }
    return array;
}

let array = randomArray();

const arrayEl = document.querySelector('#array');

const renderElement = value => {
    const element = document.createElement('div');
    element.classList.add('element');
    element.innerHTML = value;
    arrayEl.appendChild(element);
};

const renderArray = () => {
    arrayEl.innerHTML = '';
    array.forEach(renderElement);
};

renderArray();

const buttonRandomArrayEl = document.querySelector('#random-array');
const buttonSelectionSortEl = document.querySelector('#selection-sort');
const buttonInsertionSortEl = document.querySelector('#insertion-sort');
const buttonBubbleSortEl = document.querySelector('#bubble-sort');
const buttonQuickSortEl = document.querySelector('#quick-sort');

buttonRandomArrayEl.onclick = () => {
    array = randomArray();
    renderArray();
}

buttonSelectionSortEl.onclick = () => {
    selectionSort(array);
    renderArray();
}

buttonInsertionSortEl.onclick = () => {
    insertionSort(array);
    renderArray();
}

buttonBubbleSortEl.onclick = () => {
    bubbleSort(array);
    renderArray();
}

buttonQuickSortEl.onclick = () => {
    quickSort(array);
    renderArray();
}