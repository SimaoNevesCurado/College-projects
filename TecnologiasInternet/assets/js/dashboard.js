const hamburger =document.querySelector('.hamburger');
const navList =document.querySelector('nav ul');
//ao clicar no botao cuja class  é indicada a cima, adiciona a class "active" no componente em questao
//essa class contem os estilos do menu lateral
hamburger.addEventListener('click', () =>{

    hamburger.classList.toggle('active');
    navList.classList.toggle('active');
});