import express from 'express';
import cors from 'cors';
const app = express();
app.use(cors());
app.use(express.json());
let users = [];
let nextId = 1;
// Ruta para registrar usuario
app.post('/users/register', (req, res) => {
    const { username, email } = req.body;
    if (!username || !email) {
        return res.status(400).json({ error: 'Faltan datos' });
    }
    const user = { id: nextId++, username, email };
    users.push(user);
    res.status(201).json(user);
});
// Ruta para listar usuarios
app.get('/users', (req, res) => {
    res.json(users);
});
// Ruta para ver perfil de usuario por id
app.get('/users/:id', (req, res) => {
    const user = users.find(u => u.id === Number(req.params.id));
    if (!user)
        return res.status(404).json({ error: 'Usuario no encontrado' });
    res.json(user);
});
app.get('/health', (req, res) => {
    res.json({ status: 'ok' });
});
app.listen(3000, () => {
    console.log('API running on port 3000');
});
//# sourceMappingURL=index.js.map