const { request } = require("express");
const express = require("express");
const app = express();
const WebSocket = require('ws');
const wsServer = new WebSocket.Server({ port: 3000 });
let clients = new Set();
let history = [];

wsServer.on('connection', onConnect);

function sendEverybody(obg) {
    let msg = JSON.stringify(obg);
    for (let key of clients) {
        key.send(msg);
    }
}

function  onConnect(Client) {
    Client.on('message', function(message) {
        let add = JSON.parse(message);
        add.date = nowTime();
        history.push(add);
        sendEverybody(add);
    });
    Client.on('close', (event) => {
        clients.delete(event.target);
        console.log('close');
    })
    clients.add(Client);
    console.log('Connect done');
}

app.use(express.json());
app.use(express.static(__dirname));

app.get('/download', function(request, response) {
    response.status(201).send(JSON.stringify(history));
});

app.post('/send', function(request, response) {
    let add = {
        date: request.body.date,
        login: request.body.login,
        text: request.body.text,
    };
    if (history.length == 49)
        history.unshift();
    history.push(add);
    response.status(201).send();
})

function  nowTime() {
    let date = new Date();
    let day = String(date.getDate());
    let mounth = String(date.getMonth() + 1);
    let hours = String(date.getHours());
    let minutes = String(date.getMinutes());

    if (day.length == 1)
        day = '0' + day;
    if (mounth.length == 1)
        mounth = '0' + mounth;
    if (hours.length == 1)
        hours = '0' + hours;
    if (minutes.length == 1)
        minutes = '0' + minutes;
    return (day + ':' + mounth + ':'
    + date.getFullYear() + ' ' + hours + ':' + minutes);
}

app.listen(8000);