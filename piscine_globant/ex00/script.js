/* registra un manejador para el evento "click" 
del elemento con id "restart-btn". 
Al hacer clic en ese elemento se ejecuta la función init.*/
document.getElementById('restart-btn').addEventListener('click', init);

function init(){
    console.log('Inicializar el juego');
}