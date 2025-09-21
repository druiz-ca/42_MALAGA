import Fastify, { fastify } from 'fastify';
import cors from '@fastify/cors';
async function main() {
    const fastify = Fastify();
    await fastify.register(cors);
    let variable = '';
    fastify.post('/post', (request, devolver) => {
        const { nombre } = request.body;
        variable = nombre;
        devolver.send({ ok: true });
    });
    fastify.get('/users', (request, reply) => {
        reply.send(variable);
    });
    fastify.listen({ port: 3001 }, () => {
        console.log('la API está en marcha');
    });
}
main();
//# sourceMappingURL=index.js.map