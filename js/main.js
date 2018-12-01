const randomArray = (length = 100) => {
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

buttonRandomArrayEl.onclick = () => {
    array = randomArray();
    renderArray();
}

const sortButtons = document.querySelectorAll('#sort-array > button');
const sortFunctions = [selectionSort, insertionSort, bubbleSort, quickSort];

for(let i = 0; i < sortButtons.length; i++) {
    sortButtons[i].onclick = () => {
        sortFunctions[i](array);
        renderArray();
    }
}
