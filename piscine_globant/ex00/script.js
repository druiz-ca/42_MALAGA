/* registra un manejador para el evento "click" 
del elemento con id "restart-btn". 
Al hacer clic en ese elemento se ejecuta la función init.*/
document.getElementById('restart-btn').addEventListener('click', init);

function init(){
    console.log('Inicializar el juego');
}

// Array de la cuadricula
let grid_array = [];

// Función para inicializar el tablero
    // LLena la matriz con 0s
    // Llama 2x a addRandom... para poner 2 fichas
function initGrid(){
    grid_array = [];
    for (let i = 0; i < 4; i++)
        grid_array.push([0,0,0,0]);
    addRandomTile();
    addRandomTile();
    console.log(grid_array);
}

// Función para añadir una ficha aleatoria
function addRandomTile(){
    let aux_array = []; // array vacío auxiliar
    
    // Recorre todas las pos. de grid
    for (let r = 0; r < 4; r++){
        for (let c = 0; c < 4; c++)
            // Busca todas las posiciones vacías(0) de la cuadricula
            if (grid_array[r][c] === 0) 
                // almacena todas las pos. de la cuadrícula que estén a 0
                aux_array.push([r, c]);
    }
    
    if (aux_array.length === 0) 
        return false;
    
    // Elige una al azar
        // Genera un num random entre 0 y long del array
        // Lo convierte en un entero
        // Mediante desestructuración almacena la fila y columna random
    let [row, col] = aux_array[Math.floor(Math.random() * aux_array.length)];

    // Coloca un 2 (el 90% de las veces) o un 4
        // genera un num random entre 0 y 1
        // si es menor a 0,9 escoje 2 sino 4
    grid_array[row][col] = Math.random() < 0.9 ? 2 : 4;
    return true;
}

// Llama a la ft initGrid al cargar la página
window.addEventListener('load', initGrid);