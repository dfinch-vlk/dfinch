const express = require("express");
const mysql = require('mysql2');
const multer = require('multer');
const cookieParser = require('cookie-parser');
const crypto = require('crypto');
const fs = require("fs");

const iv = crypto.randomBytes(16);
const key = crypto.scryptSync('secret', 'salt', 32);

const app = express();
const conn = mysql.createConnection( {
    host: 'localhost',
    user: 'root',
    database: 'Vcloud',
    password: '17776990',
    }
);

function cryptoToken(text) {
    let encyptedData = crypto.createHash('sha1').update(text).digest("hex");
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
    const token = req.header('Authorization');
    conn.query(`SELECT login FROM accounts WHERE token="${token}";`, (err, answer) => {
        res.status(200).send(JSON.stringify({login: answer[0].login,}));
    });
});

app.get('/infoFiles', (req, res) => {
    const token = req.header('Authorization');
    let id;
    conn.query(`SELECT id FROM accounts WHERE token="${token}";`, (err, answer) => {
        id = answer[0].id;
        console.log('infoFiles id user: ', id);
        conn.query(`SELECT id, original FROM files WHERE login=${id};`, (err, answer) => {
            console.log('infoFiles: ', answer);
            res.status(200).send(answer);
        })
    })
});

app.post('/addFile', (req, res) => {
    const token = req.header('Authorization');
    console.log(req.file);
    let id;
    conn.query(`SELECT id FROM accounts WHERE token="${token}";`, (err, answer) => {
        id = answer[0].id;
        console.log('id: ', id);
        conn.query(`INSERT files(name, original, login) VALUES("${req.file.filename}", "${req.file.originalname}", ${id});`, (err, answer) => {
            if (err)
                console.log(err);
            res.status(201).send();
        })
    })
})

app.delete('/deleteFile', (req, res) => {
    const id = req.body.id;
    let fileName;

    conn.query(`SELECT name FROM files WHERE id=${id};`, (err, answer) => {
        fileName = answer[0].name;
        fs.unlink(__dirname + '/files/' + fileName, () => {
            conn.query(`DELETE FROM files WHERE id=${id};`, (err, answer) => {
                res.status(201).send();
            })
        })
    })
})

app.get('/downloadFile', (req, res) => {
    const id = req.header('ID');
    let fileName;
    conn.query(`SELECT name FROM files WHERE id=${id};`, (err, answer) => {
        fileName = answer[0].name;
        fs.readFile(__dirname + '/files/' + fileName, (err, data) => {
            if (err) {
                console.log(err);
                res.status(401).send();
                return ;
            }
            res.status(201).send(data);
        })
    })
})

app.use('/download', (req, res) => {
   const fileName = req.url.slice(1);
   let original;
   conn.query(`SELECT original FROM files WHERE name="${fileName}";`, (err, answer) => {
       if (answer[0] == undefined) {
            res.status(401).send("<h1>File don't fined</h1>")
            return ;
       }
       original = answer[0].original;
       fs.copyFile(__dirname + '/files/' + fileName, __dirname + '/' + original, (err) => {
           if(err)
            console.log(err);

            fs.readFile(__dirname + '/' + original, (err, data) => {
                res.status(200).send(data);
                fs.unlink(__dirname + '/' + original, (err) => {
                    if (err)
                        console.log(err);
                    else
                        console.log('unlink done');
                });
            })
       })
   })
})

app.listen(80);