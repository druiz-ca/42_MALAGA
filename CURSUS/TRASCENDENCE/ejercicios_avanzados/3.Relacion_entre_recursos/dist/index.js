import Fastify from "fastify";
import cors from '@fastify/cors';
import { promises as fs } from 'fs';
async function main() {
    const fastify = Fastify();
    await fastify.register(cors, {
        methods: ['GET', 'POST', 'DELETE', 'PUT']
    });
    let arrayUsuarios = await leerUsuarios();
    let arrayPosts = [];
    // GESTION DEL ARCHIVO
    async function leerUsuarios() {
        const datos = await fs.readFile('usuarios.json', 'utf-8');
        return JSON.parse(datos);
    }
    async function guardarUsuarios(arrayUsuarios) {
        await fs.writeFile('usuarios.json', JSON.stringify(arrayUsuarios, null, 2));
    }
    // ---------------------
    fastify.post('/post', async (solicitud, respuesta) => {
        // cuando extraes + de 1 parámetro necesitas {}
        // as inter... especifica q debe contener el objeto
        // DESESTRUCTURACIÓN DEL OBJETO:
        // en vez de: const objeto -> objeto.nombre / objeto.email
        // lo desestructuras: {nombre, email}
        // útil para q compruebe q exactamente recibe esos parámtros
        // pq si es objeto = ... no controla lo que recibe!!
        const objeto = solicitud.body;
        // para + seguridad, desestructurar -> {nombre, email}
        arrayUsuarios.push(objeto);
        await guardarUsuarios(arrayUsuarios);
        respuesta.send('Guardado');
    });
    // Ft para botón CONSULTAR
    fastify.get('/get', async (solicitud, respuesta) => {
        respuesta.send(arrayUsuarios);
    });
    fastify.listen({ port: 3000 }, () => {
        console.log('API is listening');
    });
    fastify.get('/posts/:nombre', async (solicitud, respuesta) => {
        // Solicitud.params equivale a :nombre + es de tipo string
        // Extrae el nombre (.nombre) del parámetro del objeto recibido 
        // en la solicitud
        const nombreUsuario = solicitud.params.nombre;
        //Filtra los posts que pertenecen a este usuario
        const postsUsuario = arrayPosts.filter(post => post.usuario === nombreUsuario);
        respuesta.send(postsUsuario);
    });
    // Esta función es identíca a crear nuevo usuario + post pero aquí especificas el usuario 
    // en  la URL y en el normal no
    fastify.post('/posts/:nombre', async (solicitud, respuesta) => {
        const nombrePosteador = solicitud.params.nombre;
        const { contenido } = solicitud.body;
        arrayPosts.push({ usuario: nombrePosteador, contenido });
        respuesta.send('Post creado para el usuario ' + nombrePosteador);
    });
}
main();
//# sourceMappingURL=index.js.map