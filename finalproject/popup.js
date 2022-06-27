document.addEventListener('DOMContentLoaded', function(){
    var btn = document.getElementById('hydrate');
    btn.addEventListener('click', function() {
        const messages = new Array(
            "You can do this!",
            "Don't give up!",
            "Thank you!",
            "You're the best!",
            "Mmmmm wet",
            "Hydrate or Diedrate!",
            "True power stems from a barrel of a gun"
        );
        let m = messages[Math.random()*6];
        alert(m);
        console.log("Message displayed");
    }, false);
}, false);