// improta el Framework
import Fastify from "fastify"; 
//Importa el plugin CORS para permitir peticiones de front, navegador)
import cors from '@fastify/cors';
// Importa las funciones asíncronas de manejo de archivos
import {promises as fs} from 'fs';

async function main(){
    //Crea el servidor Fastify (una instancia del servidor(un objeto))
    const fastify = Fastify(); 
    // Mientras no termine de configurar el plugin cors no avanza!
    await fastify.register(cors, {
        methods: ['GET', 'POST', 'DELETE', 'PUT']
    });

    interface interUsuarios{
        nombre: string;
        email: string;
    }

    // esta ft tiene que estar antes de ser llamada sino no carga
    async function leerUsuarios(){
        try{
            const datos = await fs.readFile('usuarios.json', 'utf-8');
            return JSON.parse(datos);
        } catch (e) {
            return [];
        }
    }

    let arrayUsuarios: interUsuarios[] = await leerUsuarios();

    // te obliga a especificar el tipo de dato q contiene el array
    async function guardarUsuarios(arrayUsuarios: interUsuarios[]){
        await fs.writeFile('usuarios.json', JSON.stringify(arrayUsuarios, null, 2));
    }

    fastify.post('/post', async (solicitud, respuesta) => {
        const {nombre, email} = solicitud.body as interUsuarios;
        arrayUsuarios.push({nombre, email});
        await guardarUsuarios(arrayUsuarios);
        respuesta.send('Guardado');
    })

    fastify.get('/posts/:nombre', async (solicitud, respuesta) => {
    const nombre = (solicitud.params as {nombre: string}).nombre;
    const postsUsuario = arrayUsuarios.filter(post => post.nombre === nombre);
    respuesta.send(postsUsuario);
    });
    // defino una constante TOKEN para que tenga que comprobarlo el back
    const TOKEN = 'mi_token';

    fastify.delete('/delete/:nombre', async (solicitud, respuesta) => {
        const token = solicitud.headers['authorization'];
        if(token !== TOKEN)
            return respuesta.status(401).send('Unauthorized');
        const nombreBuscado = (solicitud.params as {nombre: string}).nombre;
        const index = arrayUsuarios.findIndex(obj_user => obj_user.nombre === nombreBuscado);
        if(index !== -1){
            // splice(empalmar) // el 1 es la cantidad de elementos  a borrar
            arrayUsuarios.splice(index, 1);
            await guardarUsuarios(arrayUsuarios);
            respuesta.send('Usuario eliminado');
        }
        respuesta.status(404).send('Doesn`t exist');

    });

    fastify.get('/get', async (solicitud, respuesta) => {
        respuesta.send(arrayUsuarios);
    });

    fastify.listen({port:3000}, () => {
        console.log('API listening');
    });
}

main();