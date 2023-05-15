
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
const alertDiv = '<div class="alert alert-danger" role="alert">';





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
                    //console.log("verificato");
                    return true;
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
takeoff();
setInterval(takeoff, 3000);




