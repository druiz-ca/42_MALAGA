import Fastify from 'fastify';
import cors from '@fastify/cors';

async function main(){
    const fastify = Fastify();
    await fastify.register(cors);

    interface interUsuarios {
        nombre: string;
        email: string;
    }
    let arrayUsuarios: interUsuarios[] = [];

    fastify.post('/post', (solicitud, respuesta) => {
        const {nombre, email} = solicitud.body as interUsuarios;
        arrayUsuarios.push({nombre, email});
        respuesta.send('Guardado');
    });

    fastify.get('/get', (solicitud, respuesta) => {
        respuesta.send(arrayUsuarios);
    });

    fastify.get('/get/:nombre', (solicitud, respuesta) => {
        const nombreBuscado = (solicitud.params as {nombre : string}).nombre;
        const usuario = arrayUsuarios.find(u => u.nombre === nombreBuscado);
        if(usuario)
            respuesta.send(usuario);
        else
            respuesta.status(404).send('No existe');
    });

    fastify.delete('/delete/:nombre', (solicitud, respuesta) => {
        const nombreBuscado = (solicitud.params as {nombre: string}).nombre;
        const index = arrayUsuarios.findIndex(obj_user => obj_user.nombre === nombreBuscado);
        if(index !== -1){
            arrayUsuarios.splice(index, 1);
            respuesta.send('Usuario eliminado');
        }else
            respuesta.status(404).send('No existe el nombre');
    });

    fastify.put('/put/:nombre', (solicitud, respuesta) => {
        // Extraigo el nombre del parámetro de la solicitud (/put/:nombre)
        const nombreBuscado = (solicitud.params as {nombre: string}).nombre;
        // Extraigo el campo email del body de la solicitud
        const {email} = solicitud.body as {email:string};

        //Busco el usuario en el array
        const usuario = arrayUsuarios.find(obj_user => obj_user.nombre === nombreBuscado);
        if(!usuario)
            return respuesta.status(404).send('No existe ese nombre');

        //Actualizo el email
        usuario.email = email;
        respuesta.send('Email actualizado');
    });

    fastify.listen({port: 3000}, () => {
        console.log('API escuchando');
    });
}

main();