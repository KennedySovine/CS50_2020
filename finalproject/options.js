//Saves options to chrome storage
function save_options() {
    var animal = document.getElementById('animal').value;
    chrome.storage.sync.set({
        animalType: animal
    },
    function() {
        //Update status to let user know options were saved
        var status = document.getElementById('status');
        status.textContent = 'Options saved.';
        setTimeout(function(){
            status.textContent = '';
        }, 750);
    });
}

//Restores select box state using the preferences stored in chrome.storage
function restore_options(){
    //Default animal = dog
    chrome.storage.sync.get({
        animal: 'dog'
    }, function(items){
        document.getElementById('animal').value = items.animal;
    });
}
document.addEventListener('DOMContentLoaded', restore_options);
document.getElementById('save').addEventListener('click', save_options);