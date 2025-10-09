import Fastify from "fastify";
import cors from '@fastify/cors';
import { promises as fs } from 'fs';
async function main() {
    const fastify = Fastify();
    await fastify.register(cors, { methods: ['GET', 'POST', 'DELETE', 'PUT'] });
    let arrayUsuarios = await leerUsuarios();
    async function leerUsuarios() {
        const datosLeidos = await fs.readFile('usuarios.json', 'utf-8');
        return JSON.parse(datosLeidos);
    }
    async function guardarUsuarios(arrayUsuarios) {
        await fs.writeFile('usuarios.json', JSON.stringify(arrayUsuarios, null, 2));
    }
    fastify.post('/post', async (solicitud, respuesta) => {
        const { nombre, email } = solicitud.body;
        arrayUsuarios.push({ nombre, email });
        await guardarUsuarios(arrayUsuarios);
        respuesta.send('Guardado');
    });
    fastify.get('/get', (solicitud, respuesta) => {
        respuesta.send(arrayUsuarios);
    });
    fastify.listen({ port: 3000 }, () => {
        console.log('API is listening');
    });
}
main();
//# sourceMappingURL=index.js.map