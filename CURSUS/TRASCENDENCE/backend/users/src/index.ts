import Fastify from 'fastify';
import cors from '@fastify/cors';

const fastify = Fastify();
await fastify.register(cors);

// Array para guardar usuarios en memoria
interface User {
  id: number;
  username: string;
  email: string;
}
let users: User[] = [];
let nextId = 1;

// Ruta para registrar usuario
fastify.post('/users/register', async (request, reply) => {
  const { username, email } = request.body as { username: string; email: string };
  if (!username || !email) 
    return reply.status(400).send({ error: 'Faltan datos' });
  const user: User = { id: nextId++, username, email };
  users.push(user);
  reply.status(201).send(user);
});

// Ruta para listar usuarios
fastify.get('/users', async (request, reply) => {
  reply.send(users);
});

// Ruta para ver perfil de usuario por id
fastify.get('/users/:id', async (request, reply) => {
  const id = Number((request.params as { id: string }).id);
  const user = users.find(u => u.id === id);
  if (!user) return reply.status(404).send({ error: 'Usuario no encontrado' });
  reply.send(user);
});

// Ruta de salud
fastify.get('/health', async (request, reply) => {
  reply.send({ status: 'ok' });
});

fastify.listen({ port: 3000 }, (err, address) => {
  if (err) throw err;
  console.log('API running on port 3000');
});