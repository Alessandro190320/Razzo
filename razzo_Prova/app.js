
console.log("ciao da javascript esterno");
window.setTimeout(timer, 5000);

/**
 * timer
 * @param null
 */
function timer() {
    //console.clear()
}
const textEmail = document.getElementById("exampleInputEmail1"); // textEmail
const psw = document.getElementById("exampleInputPassword1");
const ErrorBox = document.getElementById("ErrorBox");
const checkbox = document.getElementById("exampleCheck1");
const alertDiv = '<div class="alert alert-danger" role="alert">';

var i = 0;

sessionStorage.setItem("state", "true"); // salvo il valore



function validate() {
    if ((textEmail.value == "") || (textEmail.value == "undefined")) // controllo se è vuota
    {
        ErrorBox.innerHTML = alertDiv + '<strong>Attento manca la mail</strong>' + '</div>';
        textEmail.focus();
        ErrorBox.innerHTML = alertDiv + '<strong>Attento manca la psw</strong>' + '</div>';
        psw.style = "border: 2px red solid; background-color:#DC6161";
        return false;
    }
    else {
        textEmail.style = "";

        if (psw.value == "") {
            ErrorBox.innerHTML = alertDiv + '<strong>Attento manca la psw</strong>' + '</div>';
            psw.style = "border: 2px red solid; background-color:#DC6161";
            return false;
        }
        else {
            if (textEmail.value != "Prova@Prova") {
                ErrorBox.innerHTML = alertDiv + '<strong>Email sbagliata</strong>' + '</div>';
                textEmail.style = "border: 2px red solid; background-color:#DC6161;";
                return false

            } else {
                if (psw.value == "prova") {
                    console.log("verificato");
                    if (i % 2 == 0) {
                        console.log("stateless")
                        return true; // torna vero
                    }
                    else {
                        // login
                        console.log("state");
                        if (!sessionStorage.getItem('state')) {
                            sessionStorage.setItem("state", "true"); // salvo il valore
                            console.log(sessionStorage.getItem('state'));
                            return true;
                        }
                        else {
                            console.log("state già allocato");
                            sessionStorage.clear();
                            sessionStorage.setItem("state", "true"); // salvo il valore
                            return true;
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

function ricordami() {
    i++;
    console.log("state = " + i);
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
            navigator.bluetooth.requestDevice({
                acceptAllDevices: true
            })
        }
        else
            console.log("off");
    });
}

bluetoothConnetion();
takeoff();
setInterval(takeoff, 3000);




