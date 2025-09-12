import Fastify from 'fastify';           // Importa el framework Fastify para crear el servidor web.
import cors from '@fastify/cors';         // Importa el plugin CORS para permitir peticiones de otros orígenes.

const fastify = Fastify();                // Crea una instancia de la aplicación Fastify.

// Registra el plugin CORS para permitir peticiones desde cualquier origen.
await fastify.register(cors);

// Define una interfaz para los usuarios.
interface User {
  id: number;
  username: string;
  email: string;
}

// Array para guardar usuarios en memoria (sin base de datos).
let users: User[] = [];
let nextId = 1;

// Ruta para registrar usuario (POST /users/register).
fastify.post('/users/register', async (request, reply) => {
  const { username, email } = request.body as { username: string; email: string };
  if (!username || !email) {
    return reply.status(400).send({ error: 'Faltan datos' }); // Valida los datos recibidos.
  }
  const user: User = { id: nextId++, username, email }; // Crea el usuario con un id único.
  users.push(user);                                     // Guarda el usuario en el array.
  reply.status(201).send(user);                         // Devuelve el usuario creado.
});

// Ruta para listar todos los usuarios (GET /users).
fastify.get('/users', async (request, reply) => {
  reply.send(users);                                    // Devuelve el array de usuarios.
});

// Ruta para ver perfil de usuario por id (GET /users/:id).
fastify.get('/users/:id', async (request, reply) => {
  const id = Number((request.params as { id: string }).id);
  const user = users.find(u => u.id === id);            // Busca el usuario por id.
  if (!user) return reply.status(404).send({ error: 'Usuario no encontrado' });
  reply.send(user);                                     // Devuelve el usuario encontrado.
});

// Ruta de salud para comprobar que el servidor funciona (GET /health).
fastify.get('/health', async (request, reply) => {
  reply.send({ status: 'ok' });                         // Devuelve un estado "ok".
});

// Inicia el servidor en el puerto 3000.
fastify.listen({ port: 3000 }, (err, address) => {
  if (err) throw err;
  console.log('API running on port 3000');   
           })       // Muestra mensaje en consola cuando está