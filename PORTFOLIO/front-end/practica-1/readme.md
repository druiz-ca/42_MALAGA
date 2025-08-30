GitHub Copilot

Plan de práctica ultra básica (pensado para mantener foco corto). Haz 1 bloque, descansa 2‑3 min, sigue.

Bloque 0 (Preparar)
Crea un archivo index.html y enlaza script.js.

````html
<!DOCTYPE html>
<html lang="es">
<head><meta charset="UTF-8"><title>JS 0</title></head>
<body>
  <h1 id="titulo">Prueba JS</h1>
  <button id="btn">Click</button>
  <p id="msg"></p>
  <script src="script.js"></script>
</body>
</html>
````

Crea script.js (vacío).

Bloque 1 (Primer output)
Objetivo: ver algo.
````javascript
console.log("Hola JS");
````
Abre la consola y verifica.

Bloque 2 (Variables + reasignar)
````javascript
let contador = 0;
console.log("Contador inicial:", contador);
contador = contador + 1;
console.log("Después:", contador);
````

Bloque 3 (Seleccionar elementos)
````javascript
const btn = document.getElementById("btn");
const msg = document.getElementById("msg");
msg.textContent = "Listo.";
````

Bloque 4 (Evento click)
````javascript
btn.addEventListener("click", () => {
  console.log("Click!");
});
````

Bloque 5 (Actualizar texto)
````javascript
let clicks = 0;
btn.addEventListener("click", () => {
  clicks++;
  msg.textContent = "Clicks: " + clicks;
});
````

Bloque 6 (Función separada)
````javascript
function actualizar() {
  msg.textContent = "Clicks: " + clicks;
}
btn.addEventListener("click", () => {
  clicks++;
  actualizar();
});
````

Bloque 7 (Toggle mostrar/ocultar)
Añade en HTML:
````html
<p id="extra" style="display:none">Texto oculto</p>
<button id="toggle">Mostrar/Ocultar</button>
````

JS:
````javascript
const extra = document.getElementById("extra");
const toggle = document.getElementById("toggle");
toggle.addEventListener("click", () => {
  const visible = extra.style.display === "block";
  extra.style.display = visible ? "none" : "block";
});
````

Bloque 8 (Clase CSS en lugar de display)
Añade en <head>:
````html
<style>
.hidden { display:none; }
</style>
````

JS:
````javascript
extra.classList.add("hidden");
toggle.addEventListener("click", () => {
  extra.classList.toggle("hidden");
});
````

Bloque 9 (Mini reto)
Crea otro botón “Reset” que ponga clicks a 0 y actualice pantalla.

Bloque 10 (Refuerzo)
Escribe con tus palabras qué hace cada línea (comentarios sobre el código).

