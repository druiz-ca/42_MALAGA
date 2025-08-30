
const button = document.getElementById("boton");
const paragrafo = document.getElementById("mensaje");
const bt_reset = document.getElementById("reset");

function resetear() {
    paragrafo.textContent = 0
}

let numero = 0;
bt_reset.addEventListener("click", () => {
    resetear(); //lleva ()!!!
});
button.addEventListener("click", () => {
    numero += 1;
    paragrafo.textContent = numero;
});

const bt_toggle = document.getElementById("toggle");
const p_extra = document.getElementById("extra");

bt_toggle.addEventListener("click", () =>{
    if(p_extra.style.display === 'none')
        p_extra.style.display = 'block';
    else
        p_extra.style.display = 'none';
});

const bt_toggle2 = document.getElementById("toggle2");
const p_extra2 = document.getElementById("extra2");

// Añade una clase a la etiqueta
p_extra2.classList.add("clase_none");

bt_toggle2.addEventListener("click", () => {
    p_extra2.classList.toggle("clase_none");
    // toggle desvincula la clase especificada
});