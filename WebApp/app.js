
console.log("ciao da javascript esterno");
window.setTimeout(timer, 5000);

/**
 * timer
 * @param null
 */
function timer() {
    //console.clear()
}
const textEmail = document.getElementById("exampleInputEmail1");
const ErrorBox = document.getElementById("ErrorBox");
const alertDiv = '<div class="alert alert-danger" role="alert">';

function validate() {
    if (textEmail.value == "") // controllo se è vuota
    {
        ErrorBox.innerHTML = alertDiv + '<strong>Attento manca la mail</strong>' + '</div>';
        return false;
    }

    return false;
}


/**
 * Animated head icon function
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




