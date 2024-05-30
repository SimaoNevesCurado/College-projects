
//dark - light modes

const darkModeButton = document.getElementById('darkModeButton');
const body= document.body;
const enableDarkMode= ( )=> {
    body.classList.add('dark-mode');

}

const disableDarkMode= ()=> {
    body.classList.remove('dark-mode');

}
darkModeButton.addEventListener('change',()=>{

    if(darkModeButton.checked){
        disableDarkMode()
    }else{
        enableDarkMode();
    }

});
