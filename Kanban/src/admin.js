if (window.localStorage.getItem('type_account') == undefined || window.localStorage.getItem('type_account') == 0)
    document.location.href = '/index.html';

let board_id;

downloadPage();

function downloadPage() {
    fetch('/downloadBoardId', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify({id: window.localStorage.getItem('kanban_id')}),
    }).then(result => result.json())
    .then(obj => {
        board_id = obj.board_id;
        console.log(board_id);
        fetch('/downloadLoginAdmin', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json;charset=utf-8',
            },
            body: JSON.stringify({id: board_id}),
        }).then(result => result.json())
        .then(obj => {
            for (let key of obj)
                showLogin(key.id, key.login);
        });
        fetch('/downloadTaskAdmin', {
            method: 'POST',
            headers: {
                'Content-Type': 'application/json;charset=utf-8',
            },
            body: JSON.stringify({id: board_id}),
        }).then(result => {
            if (!result.ok)
                throw new Error();
            return result.json();
        })
        .then(obj => {
            console.log(obj);
            for (let key of obj) {
                document.getElementById('tasks').append(createCard(key.text, key.status, key.Id));
            }
        })
    });
}

function showLogin(id, login) {
    const list_login = document.createElement('p');
    const select_login = document.createElement('option');
    const select_delete = document.createElement('option');

    list_login.setAttribute('class', 'list_login');
    list_login.innerHTML = login;
    select_login.innerHTML = login;
    select_login.setAttribute('value', id);
    select_delete.innerHTML = login;
    select_delete.setAttribute('value', id);
    document.getElementById('logins').append(list_login);
    document.getElementById('delete_login').append(select_delete);
    document.getElementById('new_task_login').append(select_login);
}

document.getElementById('add_new_task').addEventListener('click', () => {
    const text = document.getElementById('new_task_text').value;
    const login = document.getElementById('new_task_login').value;
    const status = document.getElementById('new_task_status').value;

    if (!text.length || !login.length) {
        document.getElementById('new_task_error').innerHTML = 'Enter task and login!';
        setTimeout(() => {
            document.getElementById('new_task_error').innerHTML = ''; 
        }, 1500);
        return ;
    }
    fetch('/addNewTask', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify({
            login: login,
            text: text,
            status: status,
            id_table: board_id,
        }),
    });
    document.getElementById('new_task_text').value = '';
    document.location.href = document.location.href;
})

console.log('id: ' + window.localStorage.getItem('kanban_id'));

document.getElementById('exit').addEventListener('click', () => {
    window.localStorage.removeItem('kaban_id');
    window.localStorage.removeItem('type_account');
    document.location.href = '/';
})

document.getElementById('board').addEventListener('click', () => {
    document.location = '/board.html';
})

document.getElementById('button_add').addEventListener('click', () => {
    const input = document.getElementById('input_add');
    const err = document.getElementById('add_login_error');
    
    console.log(input.value);
    if (!input.value) {
        err.innerHTML = 'Enter login';
        setTimeout(() => {err.innerHTML = ''}, 1500);
        return ;
    }
    fetch('/addNewAccountOnBoard', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify({
            login: input.value,
            table: board_id,
        }),
    }).then(result => {
        if (!result.ok) {
            console.log('error');
            err.innerHTML = 'Error';
            setTimeout(() => {err.innerHTML = ''}, 1500);
            throw new Error();
        }
        else
            return result.json();
    }).then(obj => {
        showLogin(obj.id, obj.login);
    })
});

document.getElementById('delete_button').addEventListener('click', () => {
    fetch('/deleteLoginAdmin', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify({id: document.getElementById('delete_login').value, id_table: board_id,}),
    }).then(() => {
        window.location.href = window.location.href;
    });
})

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

    del.setAttribute('class', 'status del');
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
    del.addEventListener('click', (event) => {
        let id = event.target.closest('.card').getAttribute('card_id');
        fetch('/deleteTask', {
            method: 'POST', 
            headers: {
                'Content-Type': 'application/json;charset=utf-8',
            },
            body: JSON.stringify({id: id,}),
        });
        event.target.closest('.card').remove();
    })
    wait.append(document.createElement('p').innerHTML = 'Waiting');
    prog.append(document.createElement('p').innerHTML = 'In Progress');
    comp.append(document.createElement('p').innerHTML = 'Completed');
    del.append(document.createElement('p').innerHTML = 'Delete');
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
    buttons.append(wait, prog, comp, del);
    card.append(style, type_text, buttons);
    return card;
}