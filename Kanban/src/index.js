const login = document.getElementById('login');
const password = document.getElementById('password');
const sigin = document.getElementById('sigin');
const sigup = document.getElementById('sigup');

if (window.localStorage.getItem('type_account') == 0)
    document.location.href = '/account.html';
else if (window.localStorage.getItem('type_account') == 1)
    document.location.href = '/admin.html';


document.addEventListener('keydown', (event) => {
    if (event.code == 'Enter')
        sendSever('/sigin');
});

sigin.addEventListener('click', () => {
    sendSever('/sigin');
});

sigup.addEventListener('click', () => {
    sendSever('/sigup');
});

function showAnswer(text, flag) {
    let atr;
    
    if (flag == false)
        atr = 'error';
    else
        atr = 'success';
    document.getElementById('answer').innerHTML = `<p class="${atr}">${text}</p>`;
    return (1);
}

function sendSever(url) {
    if (!login.value && !password.value)
        return (showAnswer('Enter your login and password', false));
    else if (!login.value)
        return (showAnswer('Enter your login', false));
    else if (!password.value)
        return (showAnswer('Enter your password', false));
    fetch(url, {
        method: 'POST', 
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify({
            login: login.value,
            password: password.value,
        }),
    }).then(result => {
        if (result.status == 401) {
            showAnswer('Incorrect username or password', false);
            throw new Error('Incorrect username or password');
        }
        showAnswer('OK', true);
        return result.json();
    }).then(obj => {
        console.log(obj);
        if (url == '/sigin') {
            window.localStorage.setItem('kanban_id', obj.id);
            window.localStorage.setItem('type_account', obj.type);
            if (obj.type == 0) {
                setTimeout(() => {
                    document.location.href = '/account.html';
                }, 900);
                return ;
            };
            setTimeout(() => document.location.href = '/admin.html', 1000);
        }
    }).catch(err => {
        console.log(err);
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
    let del = document.createElement('div');

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