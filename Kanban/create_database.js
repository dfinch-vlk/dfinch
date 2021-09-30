const mysql = require('mysql2');
const conn = mysql.createConnection( {
    host: 'localhost',
    user: 'root',
    database: 'kanban',
    password: '17776990',
    }
);

conn.connect(err => {
    if (err)
        console.log(err);
    else
        console.log('Connect Database ---------- OK!');
});

conn.query('CREATE TABLE tasks(Id INT PRIMARY KEY AUTO_INCREMENT, text VARCHAR(100), status INT, login INT, id_table INT);', err => {
    if (err)
        console.log(err);
    else
        console.log('Create table tasks -------- OK!');
});

conn.query('CREATE TABLE accounts(Id INT PRIMARY KEY AUTO_INCREMENT, login VARCHAR(25), password VARCHAR(25), id_table INT, type INT);', err => {
    if (err)
        console.log(err);
    else
        console.log('Create table accounts ----- OK!');
});

conn.query('INSERT accounts(login, password, id_table, type) VALUES("test", "test", 0, 0);', err => {
    if (err)
        console.log(err);
    else
        console.log('Create test account -------- OK!');
});

conn.query('INSERT accounts(login, password, id_table, type) VALUES("admin", "admin", 0, 1);', (err) => {
    if (err)
        console.log(err);
    else
        console.log('Create test admin ---------- OK!');
})

conn.query('INSERT tasks(text, status, login, id_table) VALUE("hello world1", 1, 1, 0),("hello world2", 2, 1, 0),("hello world3", 3, 1, 0);', err => {
    if (err)
        console.log(err);
    else
        console.log('Create table accounts ----- OK!');
});

conn.end(err => {
    if (err)
        console.log(err);
    else
        console.log('Close connect database ---- OK!');
})