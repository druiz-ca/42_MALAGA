import Fastify from "fastify";
import cors from '@fastify/cors';
import {promises as fs} from 'fs';

async function main(){
    const fastify = Fastify();
    await fastify.register(cors, {
        methods: ['GET', 'POST', 'DELETE', 'PUT']
    });

    fastify.post('/post', async (solicitud, respuesta) => {

    })

    fastify.get('/get', async (solicitud, respuesta) => {

    });

    fastify.listen({port:3000}, () => {
        console.log('API escuchando');
    });
}

main();