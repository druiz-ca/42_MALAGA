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

    // Carga el archivo con los usuarios guardados antes de empezar
    let arrayUsuarios: interUsuarios[] = await leerUsuarios();
    
    async function leerUsuarios(): Promise<interUsuarios[]> {
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

    fastify.get('/get', (solicitud, respuesta) => {
        respuesta.send(arrayUsuarios);
    })

    fastify.listen({port:3000}, () =>{
        console.log('API escuchando');
    });
}

main();