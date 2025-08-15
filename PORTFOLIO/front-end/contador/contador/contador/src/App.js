// ...existing code...
import React, { useState } from "react";

function App() {
  const [contador, setContador] = useState(0);
  const [color, setColor] = useState("black");
  const [texto, setTexto] = useState("");
  const [lista, setLista] = useState([]);

  const incrementar = () => setContador(c => c + 1);
  const decrementar = () => setContador(c => c - 1);
  const resetear = () => setContador(0);
  const toggleColor = () => setColor(c => (c === "black" ? "tomato" : "black"));
   
  const handleAdd = () => {
    if (texto.trim() === "") return;
    setLista(l => [...l, texto.trim()]);
    setTexto("");
  };

  return (
    <div style={{ textAlign: "center", marginTop: "40px", fontFamily: "Arial" }}>
      <h1>Ejercicio: botones que hacen cosas</h1>

      <div>
        <h2 style={{ color }}>{contador}</h2>
        <button onClick={incrementar} style={{ margin: 8, padding: "8px 12px" }}>
          Incrementar
        </button>
        <button onClick={decrementar} style={{ margin: 8, padding: "8px 12px" }}>
          Decrementar
        </button>
        <button onClick={resetear} style={{ margin: 8, padding: "8px 12px" }}>
          Resetear
        </button>
        <button onClick={toggleColor} style={{ margin: 8, padding: "8px 12px" }}>
          Cambiar color
        </button>
      </div>

      <hr style={{ width: "60%", margin: "20px auto" }} />

      <div>
        <input
          value={texto}
          onChange={(e) => setTexto(e.target.value)}
          placeholder="Escribe algo y pulsa añadir"
          style={{ padding: "6px 8px", width: 250 }}
        />
        <button onClick={handleAdd} style={{ marginLeft: 8, padding: "6px 10px" }}>
          Añadir a la lista
        </button>
      </div>

      <ul style={{ listStyle: "none", padding: 0, marginTop: 18 }}>
        {lista.map((item, i) => (
          <li key={i} style={{ margin: "6px 0", background: "#f2f2f2", padding: "6px 10px", display: "inline-block" }}>
            {item}
          </li>
        ))}
      </ul>
    </div>
  );
}

export default App;
// ...existing code...