
const bt_sumar = document.getElementById('sumar');
const bt_reset = document.getElementById('reset');
const resultado = document.getElementById('resultado');

let contador = 0;
bt_sumar.addEventListener("click", () => {
    contador += 1;
    resultado.textContent = contador;
});

bt_reset.addEventListener("click", () => {
    if(contador != 0)
    {
        contador = 0;   
        resultado.textContent = contador;
    }
    else
        resultado.textContent = "ya es 0 tontorrón"
});

// 2º EJERCICIO
const bt_mostrar = document.getElementById('bt_mostrar');
const parrafo = document.getElementById('parrafo');

bt_mostrar.addEventListener("click", () => {
    if(parrafo.style.display == 'none')
        parrafo.style.display = 'block'
    else
        parrafo.style.display = 'none';
});

// 3º EJERCICIO
const bt_mostrar2 = document.getElementById('bt_mostrar2');
const parrafo2 = document.getElementById('parrafo2');

// le añado una clase a una etiqueta
parrafo2.classList.add('clase_mostrar');
bt_mostrar2.addEventListener("click", () =>{
    if(parrafo2.style.display == 'none')
        parrafo2.style.display = 'block';
    else
        parrafo2.style.display = 'none';
});

// 4º EJERCICIO
const bt_icon = document.getElementById('bt_icon');
const img_icon = document.getElementById('img_icon');
bt_icon.addEventListener("click", () => {
    img_icon.src = 'imagenes/icon-reaction.svg';
});