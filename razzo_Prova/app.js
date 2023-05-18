
console.log("ciao da javascript esterno");
window.setTimeout(timer, 5000); // imposto il timer ogni 5 secondi

/**
 * timer
 * @param null
 */
function timer() {
    //console.clear()
}
const textEmail = document.getElementById("exampleInputEmail1"); // campo form Email
const psw = document.getElementById("exampleInputPassword1"); // campo form psw
const ErrorBox = document.getElementById("ErrorBox"); // campo per comunicare gli errori
const checkbox = document.getElementById("exampleCheck1"); // check box form per state
const alertDiv = '<div class="alert alert-danger" role="alert">'; // allert di errore

const key = "Prova@Prova"; // chiave 
const password = "prova"; // password

var gatt;

// inizializzo il valore per rimanere memorizzato
var i = 0;

// da eliminare
sessionStorage.setItem("state", "true"); // salvo il valore


/**
 * fuzione che valida i campi e li confronta con le credenziali
 * @returns state form
 */
function validate() {
    if ((textEmail.value == "") || (textEmail.value == "undefined")) // controllo se manca la mail e lo comunico
    {
        ErrorBox.innerHTML = alertDiv + '<strong>Attento manca la mail</strong>' + '</div>';
        textEmail.focus();
        ErrorBox.innerHTML = alertDiv + '<strong>Attento manca la psw</strong>' + '</div>';
        psw.style = "border: 2px red solid; background-color:#DC6161";
        return false;
    }
    else {
        textEmail.style = "";

        if (psw.value == "") { // controllo se manca la password e lo comuncio 
            ErrorBox.innerHTML = alertDiv + '<strong>Attento manca la psw</strong>' + '</div>';
            psw.style = "border: 2px red solid; background-color:#DC6161";
            return false;
        }
        else {
            if (textEmail.value != key) { // se la password corrisponde alla key
                ErrorBox.innerHTML = alertDiv + '<strong>Email sbagliata</strong>' + '</div>';
                textEmail.style = "border: 2px red solid; background-color:#DC6161;";
                return false

            } else {
                if (psw.value == password) {
                    console.log("verificato");
                    if (i % 2 == 0) {
                        console.log("stateless")
                        return true; // torna vero
                    }
                    else {
                        // login
                        console.log("state");
                        if (!sessionStorage.getItem('state')) { // controllo se il valore di stato non è già stato creato 
                            sessionStorage.setItem("state", "true"); // salvo il valore
                            console.log(sessionStorage.getItem('state'));
                            return true; // torna vero
                        }
                        else { // se è stato creato, lo comunico, lo svuoto e lo risalvo
                            console.log("state già allocato");
                            sessionStorage.clear();
                            sessionStorage.setItem("state", "true"); // salvo il valore
                            return true; // torna vero
                        }

                    }
                }
                else {
                    ErrorBox.innerHTML = alertDiv + '<strong>Password sbagliata</strong>' + '</div>';
                    psw.style = "border: 2px red solid; background-color:#DC6161";
                    return false;
                }
            }


        }
    }

}

/**
 * funzione che modifica lo stato[ricordami]
 */
function ricordami() {
    i++;
    console.log("state = " + i); // comunico alla console
}

/**
 * Head animated icon function
 */
function takeoff() {
    var a;
    a = document.getElementById("takeoff");
    a.href = "./icon/favicon-pre.ico";
    setTimeout(function () {
        a.href = "./icon/favicon.ico";
    }, 1000);
    setTimeout(function () {
        a.href = "./icon/favicon-next.ico";
    }, 2000);
}

/**
 * funzione per connettersi ai dispositivi bluetooth
 */
async function bluetoothConnetion() {
    navigator.bluetooth.getAvailability().then((available) => {
        if (available) {
            console.log("On");
            navigator.bluetooth.requestDevice({ // ricerco tutti i dispositivi disponibili
                filters: [{
                    acceptAllDevices: true,
                    services: ['00001101-0000-1000-8000-00805f9b34fb']
                }]

            }).then(device => {
                console.log(device.name);
                gatt = device.gatt.connect(); // mi copio il nome del device
            })
                .catch(error => { console.error(error) });
        }
        else
            console.log("off");
    });
}

bluetoothConnetion();
takeoff();
setInterval(takeoff, 3000);




