import Fastify from 'fastify';
import cors from '@fastify/cors'
import {promises as fs} from 'fs';

async function main(){
    const fastify = Fastify();
    await fastify.register(cors, {methods: ['GET', 'POST', 'DELETE', 'PUT']});

    interface interUsuarios{
        nombre : string;
        email: string;
    }

    let arrayUsuarios: interUsuarios[] = await leerUsuarios();
    
    async function leerUsuarios() {
        try {  
            const datos = await fs.readFile('usuarios.json', 'utf-8');
            return JSON.parse(datos);
        }catch (e) {
            return []; 
        }
    }

    async function guardarUsuarios(arrayUsuarios: interUsuarios[]){
        await fs.writeFile('usuarios.json', JSON.stringify(arrayUsuarios, null, 2));
    }

    fastify.post('/post', async (solicitud, respuesta) => {
        const {nombre, email} = solicitud.body as interUsuarios;
        arrayUsuarios.push({nombre, email});
        await guardarUsuarios(arrayUsuarios);
        respuesta.send('Guardado');
    });

    fastify.put('/put/:nombre', async (solicitud, respuesta) => {
        const nombreBuscado = (solicitud.params as {nombre: string}).nombre;
        const {email} = solicitud.body as {email:string};
        const usuario = arrayUsuarios.find(objeto => objeto.nombre === nombreBuscado);
        if(!usuario)
            return respuesta.status(404).send('No existe');
        usuario.email = email;
        await guardarUsuarios(arrayUsuarios);
        respuesta.send('Email actualizado');
    });

    fastify.get('/get', (solicitud, respuesta) => {
        respuesta.send(arrayUsuarios);
    })

    fastify.listen({port:3000}, () =>{
        console.log('API escuchando');
    });
}

main();