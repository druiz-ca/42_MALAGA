import Fastify from 'fastify'; // Importa el framework Fastify para crear el servidor web.
import cors from '@fastify/cors'; // Importa el plugin CORS para permitir peticiones de otros orígenes.
async function main() {
    const fastify = Fastify(); // Crea una instancia de la aplicación Fastify.
    await fastify.register(cors); // Registra el plugin CORS.
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
    fastify.listen({ port: 3001 }, (err, address) => {
        if (err)
            throw err;
        console.log('API running on port 3000'); // Muestra mensaje en consola cuando está listo.
    });
}
main();
//# sourceMappingURL=index.js.map