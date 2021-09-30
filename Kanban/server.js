const express = require("express");
const app = express();
const mysql = require('mysql2');
const conn = mysql.createConnection( {
    host: 'localhost',
    user: 'root',
    database: 'kanban',
    password: '17776990',
    }
);

app.use(express.json());
app.use(express.static(__dirname + '/src'));

app.post('/sigin', (req, res) => {
    let answer = req.body;
    conn.query(`SELECT id, type FROM accounts
    WHERE login="${answer.login}" AND password="${answer.password}";`, (err, result) => {

        let obj = result[0];
        if (obj == undefined) {
            console.log('Account don t find');
            res.status(401).send();
            return ;
        }
        console.log('id: ' + obj.id);
        console.log('type: ', obj.type);
        res.status(201).send(JSON.stringify({id: obj.id, type: obj.type,}));
    });
});

app.post('/sigup', (req, res) => {
    let answer = req.body;
    conn.query(`SELECT login FROM accounts WHERE login="${answer.login}";`, (err, result) => {
        console.log('this -----> ' + answer);
        if (err)
            return err;
        if (result[0] == undefined) {
            console.log(answer);
            conn.query(`INSERT accounts(login, password, id_table, type) VALUE("${answer.login}", "${answer.password}", -1, 0);`);
            res.status(201).send();
            return ;
        }
        res.status(401).send();
    });
});

app.post('/downloadAccount', (req, res) => {
    let answer = req.body;
    conn.query(`SELECT * FROM tasks WHERE login=${answer.id};`, (err, result) => {
        res.status(201).send(JSON.stringify(result));
    })
});

app.post('/selectedWaiting', (req, res) => {
    let id = req.body.id;
    conn.query(`UPDATE tasks SET status=1 WHERE id=${id};`);
    res.status(201).send();
});

app.post('/selectedInProgress', (req, res) => {
    let id = req.body.id;
    conn.query(`UPDATE tasks SET status=2 WHERE id=${id};`);
    res.status(201).send();
});

app.post('/selectedComlected', (req, res) => {
    let id = req.body.id;
    conn.query(`UPDATE tasks SET status=3 WHERE id=${id};`);
    res.status(201).send();
});

app.post('/downloadBoard', (req, res) => {
    let account_id = req.body.id;
    let tmp = [];
    conn.query(`SELECT id_table FROM accounts WHERE id=${account_id};`, (err, result) => {
        conn.query(`SELECT * FROM tasks WHERE id_table=${result[0].id_table}`, (err, result) => {
            for (key of result) {
                conn.query(`SELECT login FROM accounts WHERE id=${key.login};`, (err, done) => {
                    tmp.push(done[0].login);
                });
            }
            setTimeout(() => {
                for (let i = 0; i < tmp.length; i++)
                    result[i].login = tmp[i];
                res.status(201).send(JSON.stringify(result));
            }, 100);
        })
    })
});

app.post('/downloadBoardId', (req, res) => {
    let id_account = req.body.id;
    
    conn.query(`SELECT id_table FROM accounts WHERE id=${id_account};`, (err, result) => {
        res.status(200).send(JSON.stringify({board_id: result[0].id_table}));
    })
});

app.post('/downloadLoginAdmin', (req, res) => {
    let id_table = req.body.id;
    conn.query(`SELECT id, login FROM accounts WHERE id_table=${id_table} AND type=0;`, (err, result) => {
        res.status(200).send(result);
    })
})

app.post('/addNewTask', (req, res) => {
    const answer = req.body;
    console.log(answer);
    conn.query(`INSERT tasks(text, status, login, id_table) VALUE("${answer.text}", ${answer.status}, ${answer.login}, ${answer.id_table});`, (err, result) => {
        res.status(201).send();
    });
})

app.post('/addNewAccountOnBoard', (req, res) => {
    const login = req.body.login;
    const table = req.body.table;
    let answer;

    conn.query(`SELECT id, login FROM accounts WHERE login="${login}" AND id_table=-1;`, (err, result) => {
        if (result[0] == undefined) {
            console.log('Error find!');
            res.status(401).send();
            return ;
        }
        answer = result[0];
        conn.query(`UPDATE accounts SET id_table=${table} WHERE login="${login}";`, (err) => {
            if (err) {
                console.log(err);
                return ;
            }
            res.status(201).send(answer);
        });
    })
})

app.post('/deleteLoginAdmin', (req, res) => {
    const id = req.body.id;
    const id_table = req.body.id_table;

    conn.query(`UPDATE accounts SET id_table=-1 WHERE id=${id};`);
    conn.query(`DELETE FROM tasks WHERE id_table=${id_table} AND login=${id}`);
    res.status(201).send();
})

app.post('/downloadTaskAdmin', (req, res) => {
    const id = req.body.id;
    conn.query(`SELECT * FROM tasks WHERE id_table=${id};`, (err, result) => {
        if (result == undefined) {
            res.status(401).send();
            return ;
        }
        res.status(200).send(result);
    })
})

app.post('/deleteTask', (req, res) => {
    const id = req.body.id;
    conn.query(`DELETE FROM tasks WHERE id=${id};`);
    res.status(201).send();
})

app.listen(8000);