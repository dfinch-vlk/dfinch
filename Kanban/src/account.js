const login = document.querySelector('h1');
const display = document.getElementById('cards');

if (window.localStorage.getItem('type_account') == undefined || window.localStorage.getItem('type_account') == 1)
    document.location.href = '/index.html';

downloadPage();

function downloadPage() {
    fetch('downloadAccount', {
        method: 'POST', 
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify({id: window.localStorage.getItem('kanban_id'), }),
    }).then(result => result.json())
    .then(obj => {
        console.log(obj);
        for (let key of obj) {
            display.append(createCard(key.text, key.status, key.Id));
        }
    })

}

function createCard(text, status, id) {
    let card = document.createElement('div');
    let style = document.createElement('div');
    let type_text = document.createElement('div');
    let card_text = document.createElement('p');
    let buttons = document.createElement('div');
    let wait = document.createElement('div');
    let prog = document.createElement('div');
    let comp = document.createElement('div');

    card.setAttribute('class', 'card');
    card.setAttribute('card_id', id);
    console.log('id: ' + id);
    style.setAttribute('class', 'card_style');
    type_text.setAttribute('class', 'text');
    card_text.innerHTML = text;
    type_text.append(card_text);
    buttons.setAttribute('class', 'buttons');
    wait.setAttribute('class', 'status wait');
    prog.setAttribute('class', 'status prog');
    comp.setAttribute('class', 'status comp');
    wait.addEventListener('click', selectedWaiting);
    comp.addEventListener('click', selectedComlected);
    prog.addEventListener('click', selectedInProgress);
    wait.append(document.createElement('p').innerHTML = 'Waiting');
    prog.append(document.createElement('p').innerHTML = 'In Progress');
    comp.append(document.createElement('p').innerHTML = 'Completed');
    if (status == 1) {
        wait.removeAttribute('class');
        wait.setAttribute('class', 'this_status wait');
    }
    if (status == 2) {
        prog.removeAttribute('class');
        prog.setAttribute('class', 'this_status prog');
    }
    if (status == 3) {
        comp.removeAttribute('class');
        comp.setAttribute('class', 'this_status comp');
    }
    buttons.append(wait, prog, comp);
    card.append(style, type_text, buttons);
    return card;
}

function selectedWaiting(event) {
    let target = event.target;

    if (target.getAttribute('class').substr(0, 11) == 'this_status')
        return ;

    let wait = target;
    let prog = target.nextSibling;
    let comp = prog.nextSibling;
    let id = target.closest('.card').getAttribute('card_id');

    prog.removeAttribute('class');
    prog.setAttribute('class', 'status prog');
    comp.removeAttribute('class');
    comp.setAttribute('class', 'status comp');
    wait.removeAttribute('class');
    wait.setAttribute('class', 'this_status wait');
    fetch('/selectedWaiting', {
        method: 'POST', 
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify({id: id,}),
    })
}

function selectedInProgress(event) {
    let target = event.target;

    if (target.getAttribute('class').substr(0, 11) == 'this_status')
        return ;

    let prog = target;
    let wait = target.previousSibling;
    let comp = target.nextSibling;
    let id = target.closest('.card').getAttribute('card_id');

    console.log(id);
    prog.removeAttribute('class');
    prog.setAttribute('class', 'this_status prog');
    comp.removeAttribute('class');
    comp.setAttribute('class', 'status comp');
    wait.removeAttribute('class');
    wait.setAttribute('class', 'status wait');
    fetch('/selectedInProgress', {
        method: 'POST', 
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify({id: id,}),
    })
}

function selectedComlected(event) {
    let target = event.target;

    if (target.getAttribute('class').substr(0, 11) == 'this_status')
        return ;

    let comp = target;
    let prog = target.previousSibling;
    let wait = prog.previousSibling;
    let id = target.closest('.card').getAttribute('card_id');

    prog.removeAttribute('class');
    prog.setAttribute('class', 'status prog');
    comp.removeAttribute('class');
    comp.setAttribute('class', 'this_status comp');
    wait.removeAttribute('class');
    wait.setAttribute('class', 'status wait');
    fetch('/selectedComlected', {
        method: 'POST', 
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify({id: id,}),
    });
}

document.getElementById('exit').addEventListener('click', () => {
    window.localStorage.removeItem('kaban_id');
    window.localStorage.removeItem('type_account');
    document.location.href = '/';
})

document.getElementById('board').addEventListener('click', () => {
    document.location = '/board.html';
})