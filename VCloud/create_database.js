const mysql = require('mysql2');
const conn = mysql.createConnection( {
    host: 'localhost',
    user: 'root',
    database: 'VCloud',
    password: '17776990',
    }
);

conn.connect(err => {
    if (err) {
        console.log(err);
        return ;
    }
    console.log('Create database -------- OK!');
    conn.query('CREATE TABLE files(id INT PRIMARY KEY AUTO_INCREMENT, name VARCHAR(100), original VARCHAR(40), login INT);')
    conn.query('CREATE TABLE accounts(id INT PRIMARY KEY AUTO_INCREMENT, login VARCHAR(20), password VARCHAR(20), token VARCHAR(200));');
    conn.end();
})