if (window.localStorage.getItem('type_account') == undefined)
    document.location.href = '/index.html';

document.getElementById('account').addEventListener('click', () => {
    if (window.localStorage.getItem('type_account') == 0)
        document.location.href = '/account.html';
    else if (window.localStorage.getItem('type_account') == 1)
        document.location.href = '/admin.html';
});

downloadPage();

function showCard(text, status, login) {
    let card = document.createElement('div');
    let type_text = document.createElement('div');
    let card_text = document.createElement('p');
    let card_login = document.createElement('p');

    card.setAttribute('class', 'card');
    type_text.setAttribute('class', 'text');
    card_login.setAttribute('class', 'card_login');
    card_login.innerHTML = login;
    card_text.innerHTML = text;
    type_text.append(card_text);
    card.append(type_text, card_login);
    if (status == 1)
        document.getElementById('wait').append(card);
    if (status == 2)
        document.getElementById('prog').append(card);
    if (status == 3)
        document.getElementById('comp').append(card);
}

function downloadPage() {
    fetch('/downloadBoard', {
        method: 'POST', 
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify({id: window.localStorage.getItem('kanban_id')}),
    }).then(result => result.json())
    .then(obj => {
        console.log(obj);
        for (let key of obj) {
            showCard(key.text, key.status, key.login);
        }
    });
}