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
    // de ese modo se trabaja con el array y se va guardando en el archivo
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
    // Se usa .body para extrar datos enviados en la petición
    fastify.post('/post', async (solicitud, respuesta) => {
        const {nombre, email} = solicitud.body as interUsuarios;
        arrayUsuarios.push({nombre, email});
        // espera a que termine la función guardar...
        await guardarUsuarios(arrayUsuarios);
        respuesta.send('Guardado');
    });

    // Se usa .params para extraer datos de la URL (put/:nombre)
    fastify.put('/put/:nombre', async (solicitud, respuesta) => {
        // Le dices a TS que esperas un objeto q teng una propiedad 'nombre'
        // .nombre extrae el valor de esa propiedad especificado en la URL:
        // 'put/:nombre'
        const nombreBuscado = (solicitud.params as {nombre: string}).nombre;
        const {email} = solicitud.body as {email:string};

        //Busco el usuario en el array
        const usuario = arrayUsuarios.find(objeto => objeto.nombre === nombreBuscado);
        if(!usuario)
            return respuesta.status(404).send('No existe');

        //Actualizo el email
        usuario.email = email;
        // Al usar archivos tienes que guardar cada cambio:
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