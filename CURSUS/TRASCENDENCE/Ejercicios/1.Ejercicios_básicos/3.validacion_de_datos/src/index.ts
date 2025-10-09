import Fastify from "fastify";
import cors from '@fastify/cors'

async function main(){
    const fastify = Fastify();
    await fastify.register(cors);

    let arrayNombres: string[] = [];

    fastify.post('/post', (solicitud, respuesta) => {
        const {nombre} = solicitud.body as {nombre:string};

        if(!nombre || nombre.length < 2)
            return respuesta.status(400).send('Error: nombre incorrecto');
        if (arrayNombres.includes(nombre))
            return respuesta.status(409).send('Error: el nombre ya existe');
        arrayNombres.push(nombre);
        respuesta.send({guardado: arrayNombres});
    });

    fastify.get('/get', (solicitud, respuesta) => {
        respuesta.send(arrayNombres);
    });

    fastify.listen({port: 3000}, () => {
        console.log('la API funciona');
    });
}
main();