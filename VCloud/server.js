const express = require("express");
const mysql = require('mysql2');
const multer = require('multer');
const cookieParser = require('cookie-parser');
const crypto = require('crypto');

const iv = crypto.randomBytes(16);
const key = crypto.scryptSync('secret', 'salt', 32);

const app = express();
const conn = mysql.createConnection( {
    host: 'localhost',
    user: 'root',
    database: 'VCloud',
    password: '17776990',
    }
);

function cryptoToken(text) {
    let encyptedData = crypto.createHash('sha1').update(text).digest("hex");
    console.log('crypto token = ',  encyptedData);
    return encyptedData;
}

conn.connect(err => {
    if (err)
        console.log(err);
    else
        console.log('Connect database ----- OK!');
});

app.use(express.json());
app.use(express.static(__dirname + '/src'));
app.use(cookieParser('V025-K798-K901-MAKTN'));
app.use(multer({dest:"files"}).single("filedata"));

app.post('/authorization', (req, res) => {
    conn.query(`SELECT token FROM accounts WHERE login="${req.body.login}" AND password="${req.body.password}";`, (err, answer) => {
        if (err) {
            res.status(401).send();
            console.log(err);
            return ;
        }  
        if (answer[0] == undefined) {
            res.status(401).send();
            return ;
        }
        console.log(answer);
        res.cookie('token', answer[0].token);
        res.send();
    });
});

app.post('/register', (req, res) => {
    const login = req.body.login;
    const password = req.body.password;
    conn.query(`SELECT login FROM accounts WHERE login="${login}";`, (err, answer) => {
        if (answer[0] != undefined) {
            res.send(401).send();
            return ;
        }
        let token = cryptoToken(login + password);
        conn.query(`INSERT accounts(login, password, token) VALUES("${login}", "${password}", "${token}")`, (err, answer) => {
            if (err)
                res.status(401).send();
            else {
                res.cookie('token', token);
                res.send();
            }
        })
    })
})

app.get('/checkToken', (req, res) => {
    let token = req.header('Authorization');
    console.log('Header: ' + token);
    conn.query(`SELECT id FROM accounts WHERE token="${token}";`, (err, answer) => {
        if (err || answer[0] == undefined) {
            console.log(err);
            res.status(401).send();
            return ;
        }
        res.status(200).send();
    })
});

app.get('/getLogin', (req, res) => {
    let token = req.header('Authorization');
    conn.query(`SELECT login FROM accounts WHERE="${token}";`, (err, answer) => {
        if (answer[0] == undefined) {
            res.status(401).send();
            return ;
        }
        res.status(200).send(JSON.stringify({login: answer[0].login,}));
    });
})

app.get('/getFiles', (req, res) => {
    let token = req.header('Authorization');
    let id;
    conn.query(`SELECT id FROM accounts WHERE="${token}";`, (err, answer) => {
        if (answer[0] == undefined) {
            res.status(401).send();
            return ;
        }
        id = answer[0].id;
        conn.query(``);
    });
})


app.listen(80);