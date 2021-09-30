const send = document.getElementById('send');
const input = document.querySelector('input');
const display = document.getElementById('msg_display');
const socket = new WebSocket("ws://localhost:3000");
let login;

send.addEventListener('click', sigIn);
document.addEventListener('keydown', sigInDop);

function  sigInDop(event) {
	if (event.code == 'Enter')
		sigIn();
}

function sigIn() {
	if (!input.value || input.value.length > 10)
		return ;
	login = input.value;
	input.value = '';
	setTimeout(mainPart, 500);
}

function mainPart() {
	document.getElementById('delete').remove();
	input.removeAttribute('placeholder');
	input.setAttribute('placeholder', 'Enter your message');
	send.removeEventListener('click', sigIn);
	document.removeEventListener('keydown', sigInDop);
	downloadHistory();
	socket.onmessage = function(event) {
		let obg = event.data;
		obg = JSON.parse(obg);
		showMsg(obg.date, obg.login, obg.text);
	};
	document.addEventListener('keydown', (event) => {
		if (event.code != 'Enter')
			return ;
		sendMsgServer();
	});
	send.addEventListener('click', sendMsgServer);
}

function sendMsgServer() {
	if (!input.value.length || input.value.length > 80)
		return ;
	let obg = JSON.stringify({
		login: login,
		text: input.value,
	});
	socket.send(obg);
	input.value = '';
}

function showMsg(date, login, text) {
	let msg = document.createElement('div');
	
	msg.setAttribute('class', 'msg');
	msg.innerHTML = `<p class="date_msg">${date}</p><p class="login_msg">${login}</p><p class="text_msg">${text}</p>`;
	display.append(msg);
	display.scrollTop = 9999999999999;
}

function downloadHistory() {
	fetch('/download', {
		method: 'GET',
		headers: {
			'Content-Type': 'application/json;charset=utf-8',
		}
	}).then(result => result.json())
	.then(function (obg) {
		console.log(obg);
		for (let key in obg)
			showMsg(obg[key].date, obg[key].login, obg[key].text);
	})
}