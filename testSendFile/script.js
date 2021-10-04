const download = document.querySelector('.myFile');


document.querySelector('button').addEventListener('click', () => {
    fetch('/downloadFile', {
        method: 'POST',
        body: new FormData(document.querySelector('form')),
    });
});

download.addEventListener('click', () => {
    console.log('OK');
    fetch('/sendFile', {
        method: 'GET',
    }).then(result => {
        if (!result.ok) {
            console.log(error);
            throw new Error();
        }
        return result.blob();
    }).then(file => {
        window.location.href =  URL.createObjectURL(file);
    })
})