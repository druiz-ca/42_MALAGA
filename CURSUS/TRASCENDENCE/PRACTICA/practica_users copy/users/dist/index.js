import Fastify from 'fastify'; // Importa el framework Fastify para crear el servidor web.
import cors from '@fastify/cors'; // Importa el plugin CORS para permitir peticiones de otros orígenes.
async function main() {
    const fastify = Fastify();
    let usuarios = [];
    fastify.post('/prueba_post', (request, reply) => {
        let { username } = request.body;
        if (!username)
            return reply.send({ error: 'faltan datos' });
        const user = { username };
        reply.send({ recibido: username });
    });
    fastify.get('/prueba', (request, reply) => {
        reply.send({ ok: true });
    });
    fastify.get('/health', (request, reply) => {
        reply.send({ status: 'ok' });
    });
    fastify.listen({ port: 3001 }, () => {
        console.log('funciona');
    });
}
main();
//# sourceMappingURL=index.js.map