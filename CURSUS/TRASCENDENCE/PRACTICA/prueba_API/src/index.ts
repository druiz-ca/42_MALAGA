import Fastify, { fastify } from 'fastify';
import cors from '@fastify/cors';

async function main() {
    const fastify = Fastify();

    let variable = 'prueba';

    interface Estructura_usuarios {
        id: number;
        nombre: string;
        email: string;
    }

    let array_usuarios: Estructura_usuarios[] = []


    fastify.post('/users_post', (request, reply) => 
    {
        const {nombre} = request.body as {nombre: string};
        variable = nombre;
        reply.send();
    });

    fastify.get('/users', (request, reply) => 
    {
        reply.send(variable);
    });

    fastify.get('/salud', (request, reply) =>
    {
        reply.send('API saludable');
    });

    fastify.listen({port: 3001}, () => 
    {
        console.log('API corriendo');
    });
}

main();