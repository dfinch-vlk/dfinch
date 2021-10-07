class LoginPage extends React.Component {
    render() {
    return (
    <div className="display-index-page">
        <h1>VCloud</h1>
        <input type="text" className="input-index-page" id="login" placeholder="Login" />
        <input type="password" class="input-index-page" id="password" placeholder="Password" />
        <p className="register-text-index-page">If you do not have an account, <b id="register-button">register</b></p>
        <div className="button-index-page" id="sigin">Sig in</div>
        <p className="error-text" id="error"></p>
    </div>)
    }
}

class RegisterPage extends React.Component {
    render() {
    return (
    <div className="display-index-page">
        <h1>VCloud</h1>
        <input type="text" className="input-index-page" id="login" placeholder="Login" />
        <input type="password" class="input-index-page" id="password" placeholder="Password" />
        <p className="register-text-index-page">If you have an account, <b id="login-button">log in</b></p>
        <div className="button-index-page" id="sigup">Sig up</div>
        <p className="error-text" id="error"></p>
    </div>)
    }
}

class MainPage extends React.Component {
    
    exit = () => {
        deleteCookie('token');
        downloadLoginPage();
    };

    addFile = () => {
        fetch('/addFile', {
            method: 'POST', 
            headers: {
                'Authorization': getCookie('token'),
            },
            body: new FormData(document.getElementById('form-main-page')),
        }).then(() => {
        downloadMainPage()
        document.getElementById('input__file').value = null;
        });
    };

    render() {
        return (
            <div className="display-main-page">
            <div className="files-main-page">
                <h2>Your files</h2>
                {
                    this.props.info.map(function (item) {
                        return (
                    <div className="card-file-main-page" id_file={item.id} fileName={item.original}>
                            <p className="name-card-file-main-page">{item.original}</p>
                        <div className="button-card-main-page">
                            <div className="delete-card-file-main" onClick={item.delete}><img src="delete.png" /></div>
                            <div className="download-card-file-main" onClick={item.download}><img src="download.png" /></div>
                        </div>
                    </div>
                        );
                    })
                }
            </div>
            <div className="info-download-main-page">
                <div className="info-main-page">
                    <p id="info-login-main-page">{this.props.login}</p>
                    <div id="button-exit-main-page" onClick={this.exit}><p className="button-exit-text-main-page">Exit</p></div>
                </div>
                <div className="input_wrapper">
                    <form id="form-main-page">
                        <input onChange={this.addFile} type="file" name="filedata" id="input__file" className="input input__file" />
                        <label id="label" for="input__file">+</label>
                    </form>
                </div>
            </div>
        </div>
        )
    }
}

checkToken();

function checkToken(params) {
    let token = getCookie('token');
    console.log(token);
    if (token == undefined) {
        downloadLoginPage();
        return ;
    }
    fetch('/checkToken', {
        method: 'GET',
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
            'Authorization': token,
        },
    }).then(answer => {
        if (answer.ok)
            downloadMainPage()
        else {
            console.log('error');
            downloadLoginPage();
        }
    })
}

function  downloadMainPage() {
    let login;
    let token = getCookie('token');
    fetch('/getLogin', {
        method: 'GET',
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
            'Authorization': token,
        },
    }).then(result => result.json())
    .then(obj => {
        login = obj.login;
        fetch('/infoFiles', {
            method: 'GET',
            headers: {
                'Content-Type': 'application/json;charset=utf-8',
                'Authorization': token,
            },
        }).then(result => result.json()).then(obj => {
            console.log(obj);
            for (let i = 0; i < obj.length; i++) {
                obj[i].delete = deleteEvent;
                obj[i].download = downloadFileEvent;
            }
            showMainPage(login, obj);
        })
    })
}

function showMainPage(login, info) {
    console.log(login);
    console.log(info);
    ReactDOM.render(<MainPage info={info} login={login}/>, document.querySelector('body'));
}

function sendSigin() {
    const login = document.getElementById('login');
    const password = document.getElementById('password');
    if (checkValueLength(login.value.length, password.value.length))
        return ;
    fetch('/authorization', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify({
            login: login.value,
            password: password.value,
        }),
    }).then(answer => {
        if (!answer.ok)
            throw new Error();
        downloadMainPage()
    }).catch(err => {
        showError('Invalid username or password!');
    });
}

function sendSigup() {
    const login = document.getElementById('login');
    const password = document.getElementById('password');
    if (checkValueLength(login.value.length, password.value.length))
        return ;
    fetch('/register', {
    method: 'POST',
    headers: {
        'Content-Type': 'application/json;charset=utf-8',
    },
    body: JSON.stringify({
        login: login.value,
        password: password.value,
    }),
    }).then(answer => {
        if (!answer.ok)
            throw new Error();
        downloadMainPage()
    }).catch(err => {
        showError('This login already exists!');
    })
}

function downloadLoginPage() {
    ReactDOM.render(<LoginPage />, document.querySelector('body'), () => {
        document.removeEventListener('keydown', enterSigup);
        document.getElementById('register-button').addEventListener('click', downloadRegisterPage);
        document.getElementById('sigin').addEventListener('click', sendSigin);
        document.addEventListener('keydown', enterSigin);
    });
}

function enterSigin(event) {
    if (event.code == 'Enter')
        sendSigin();
}

function enterSigup(event) {
    if (event.code == 'Enter')
        sendSigup();
}

function downloadRegisterPage() {
    ReactDOM.render(<RegisterPage />, document.querySelector('body'), () => {
        document.removeEventListener('keydown', enterSigin);
        document.getElementById('login-button').addEventListener('click', downloadLoginPage);
        document.getElementById('sigup').addEventListener('click', sendSigup);
        document.addEventListener('keydown', enterSigup)
    });
}

function getCookie(name) {
    let matches = document.cookie.match(new RegExp(
      "(?:^|; )" + name.replace(/([\.$?*|{}\(\)\[\]\\\/\+^])/g, '\\$1') + "=([^;]*)"
    ));
    return matches ? decodeURIComponent(matches[1]) : undefined;
}

function deleteCookie(name) {
    setCookie(name, "", {
      'max-age': -1
    })
}

function setCookie(name, value, options = {}) {

    options = {
      path: '/',
      ...options
    };
  
    if (options.expires instanceof Date) {
      options.expires = options.expires.toUTCString();
    }
  
    let updatedCookie = encodeURIComponent(name) + "=" + encodeURIComponent(value);
  
    for (let optionKey in options) {
      updatedCookie += "; " + optionKey;
      let optionValue = options[optionKey];
      if (optionValue !== true) {
        updatedCookie += "=" + optionValue;
      }
    }
  
    document.cookie = updatedCookie;
}

function checkValueLength(login, password) {
    if (!login && !password)
        return showError('Enter login and password!');
    if (!login)
        return showError('Enter login!');
    if (!password)
        return showError('Enter password!');
    if (login > 20 || password > 20)
        return showError('Login or password must be less than 20 characters!');
    return (0);
}

function showError(text) {
    let err = document.getElementById('error');
    err.innerHTML = text;
    setTimeout(() => {
        err.innerHTML = '';
    }, 1300);
    return (1);
}

function deleteEvent(event) {
    const id = event.target.closest('.card-file-main-page').getAttribute('id_file');
    fetch('/deleteFile', {
        method: 'DELETE',
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
        },
        body: JSON.stringify({
            id: id,
        }),
    }).then(result => {
        downloadMainPage();
    })
}

function downloadFileEvent(event) {
    const id = event.target.closest('.card-file-main-page').getAttribute('id_file');
    const fileName = event.target.closest('.card-file-main-page').getAttribute('fileName');
    console.log('id: ', id, 'name: ', fileName);
    fetch('/downloadFile', {
        method: 'GET',
        headers: {
            'Content-Type': 'application/json;charset=utf-8',
            'ID': id,
        },
    })
    .then(result => result.blob())
    .then(blob => {
        forceDownload(URL.createObjectURL(blob), fileName);
    })
}

function forceDownload(blob, filename) {
    let a = document.createElement('a');
    a.download = filename;
    a.href = blob;
    document.body.appendChild(a);
    a.click();
    a.remove();
  }
