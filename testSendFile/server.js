const express = require('express');
const { fstat } = require('fs');
const app = express();
const multer = require('multer');
const fs = require('fs');

const storageConfig = multer.diskStorage({
    destination: (req, file, cb) =>{
        cb(null, "uploads");
    },
    filename: (req, file, cb) =>{
        cb(null, file.originalname);
    }
});

app.use(multer({storage:storageConfig}).single("filedata"));
app.use(express.json());
app.use(express.static(__dirname));

app.post('/downloadFile', (req, res) => {
    let file = req.file;
    if (!file)
        console.log('Error download file');
    else {
        console.log('Download file ------ OK');
        console.log(file);
    }
    res.status(201).send();
});

app.get('/sendFile', (req, res) => {
    fs.readFile(__dirname + '/uploads/hello.txt', (err, data) => {
        if (err) {
            console.log(err);
            res.status(401).send();
            return ;
        }
        res.status(201).send(data);
    })
})

app.listen(80);