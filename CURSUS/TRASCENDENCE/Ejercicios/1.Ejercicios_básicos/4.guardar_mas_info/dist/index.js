import Fastify from "fastify";
import cors from "@fastify/cors";
async function main() {
    const fastify = Fastify();
    await fastify.register(cors);
    let arrayUsuarios = [];
    fastify.post('/post', (solicitud, respuesta) => {
        const { nombre, email } = solicitud.body;
        arrayUsuarios.push({ nombre, email });
        respuesta.send('Guardado');
    });
    fastify.get('/get', (solicitud, respuesta) => {
        respuesta.send(arrayUsuarios);
    });
    fastify.listen({ port: 3000 }, () => {
        console.log('La API está escuchando');
    });
}
main();
//# sourceMappingURL=index.js.map