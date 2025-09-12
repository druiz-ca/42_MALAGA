"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const fastify_1 = __importDefault(require("fastify")); // Importa el framework Fastify para crear el servidor web.
const cors_1 = __importDefault(require("@fastify/cors")); // Importa el plugin CORS para permitir peticiones de otros orígenes.
const fastify = (0, fastify_1.default)(); // Crea una instancia de la aplicación Fastify.
// Registra el plugin CORS para permitir peticiones desde cualquier origen.
await fastify.register(cors_1.default);
// Array para guardar usuarios en memoria (sin base de datos).
let users = [];
let nextId = 1;
// Ruta para registrar usuario (POST /users/register).
fastify.post('/users/register', async (request, reply) => {
    const { username, email } = request.body;
    if (!username || !email) {
        return reply.status(400).send({ error: 'Faltan datos' }); // Valida los datos recibidos.
    }
    const user = { id: nextId++, username, email }; // Crea el usuario con un id único.
    users.push(user); // Guarda el usuario en el array.
    reply.status(201).send(user); // Devuelve el usuario creado.
});
// Ruta para listar todos los usuarios (GET /users).
fastify.get('/users', async (request, reply) => {
    reply.send(users); // Devuelve el array de usuarios.
});
// Ruta para ver perfil de usuario por id (GET /users/:id).
fastify.get('/users/:id', async (request, reply) => {
    const id = Number(request.params.id);
    const user = users.find(u => u.id === id); // Busca el usuario por id.
    if (!user)
        return reply.status(404).send({ error: 'Usuario no encontrado' });
    reply.send(user); // Devuelve el usuario encontrado.
});
// Ruta de salud para comprobar que el servidor funciona (GET /health).
fastify.get('/health', async (request, reply) => {
    reply.send({ status: 'ok' }); // Devuelve un estado "ok".
});
// Inicia el servidor en el puerto 3000.
fastify.listen({ port: 3000 }, (err, address) => {
    if (err)
        throw err;
    console.log('API running on port 3000');
}); // Muestra mensaje en consola cuando está
//# sourceMappingURL=index.js.map