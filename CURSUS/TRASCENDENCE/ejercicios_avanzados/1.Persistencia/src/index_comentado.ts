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
    
    // siempre que necesites usar await la ft se declara como async
    // fs.readFile = ft(file system) asincrona para leer archivos q devuelve promesa
    // el Promise... = cuando la promesa se resuelva la ft devolvera un
    // array de objetos de tipo interUsuarios
    // Opcionalmente puedes especificar el tipo de dato que debe devolver:
    // ...Usuarios(): Promise <interUsuarios[]> {....
    
    // NODE.js por defecto usa ft asincronas x si maneja muchas conexiones
    // al mismo tiempo, para que no bloquee, permite controlar quien espera
    // y quien no con async - await
    // una funcion async devuelve la promesa instantaneamente (a diferencia
    //de las normales) por eso necesita el await para que no siga ejecutando
    // las siguientes lineas.
    async function leerUsuarios() {
        try {   // await pausa la ejecución hasta que la promesa se resuelve
            const datos = await fs.readFile('usuarios.json', 'utf-8');
            // convierte el texto(datos) a array de objs interUsuarios
            return JSON.parse(datos);
        }catch (e) {
        // sino existe (pq es la 1 vez) devuelve un array vacio
            return []; 
        }
    }

    async function guardarUsuarios(arrayUsuarios: interUsuarios[]){
        // await espera a que se terminen de guardar los datos
        await fs.writeFile('usuarios.json', JSON.stringify(arrayUsuarios, null, 2));
    }

    // usas async cada vez que vayas a necesitar q en esa ft haya
    // algún punto en el que quieras que espere a que termine (await)
    // Siempre q se usen FILES se necesita async - await
    // En las funciones "callback/flecha(=>)" el 'async' va después del metodo (post)
    fastify.post('/post', async (solicitud, respuesta) => {
        const {nombre, email} = solicitud.body as interUsuarios;
        arrayUsuarios.push({nombre, email});
        // espera a que termine la función guardar...
        await guardarUsuarios(arrayUsuarios);
        respuesta.send('Guardado');
    });

    fastify.put('/put', )

    fastify.get('/get', (solicitud, respuesta) => {
        respuesta.send(arrayUsuarios);
    })

    fastify.listen({port:3000}, () =>{
        console.log('API escuchando');
    });
}

main();