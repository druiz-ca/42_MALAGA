import Fastify from "fastify";
import cors from '@fastify/cors';
import {promises as fs} from 'fs';

async function main(){
    const fastify = Fastify();
    await fastify.register(cors, {methods: ['GET', 'POST', 'DELETE', 'PUT']});

    interface interUsuarios{
        nombre: string;
        email: string;
    }

    let arrayUsuarios: interUsuarios[] = await leerUsuarios();

    async function leerUsuarios(): Promise<interUsuarios[]> {
        const datosLeidos = await fs.readFile('usuarios.json', 'utf-8');
        return JSON.parse(datosLeidos);
    }

    async function guardarUsuarios(arrayUsuarios: interUsuarios[]) {
        await fs.writeFile('usuarios.json', JSON.stringify(arrayUsuarios, null, 2));
    }

    fastify.post('/post', async (solicitud, respuesta) => {
        const {nombre, email} = solicitud.body as interUsuarios;
        arrayUsuarios.push({nombre, email});
        await guardarUsuarios(arrayUsuarios);
        respuesta.send('Guardado');
    });

    fastify.get('/get', (solicitud, respuesta) => {
        respuesta.send(arrayUsuarios);
    });

    fastify.listen({port:3000}, () => {
        console.log('API is listening');
    });
}

main();