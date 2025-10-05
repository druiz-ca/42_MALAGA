/* ----------------------------------------------------------------------
                            IMPORTS Y CONFIGURACIÓN
---------------------------------------------------------------------- */
import Fastify from "fastify";
import cors from '@fastify/cors';
import { promises as fs } from 'fs';
/* ----------------------------------------------------------------------
                            FUNCION PRINCIPAL
---------------------------------------------------------------------- */
async function main() {
    const fastify = Fastify();
    await fastify.register(cors, {
        methods: ['GET', 'POST', 'DELETE', 'PUT']
    });
    // ============= Gestion del archivo de usuarios ============== //
    async function leerUsuarios() {
        const datos = await fs.readFile('usuarios.json', 'utf-8');
        return JSON.parse(datos);
    }
    async function guardarUsuarios(arrayUsuarios) {
        await fs.writeFile('usuarios.json', JSON.stringify(arrayUsuarios, null, 2));
    }
    // =========================================================== //
    // ============= ARRAY USUARIOS
    let arrayUsuarios = await leerUsuarios();
    // ============ FUNCIONES DE USUARIOS ======================== //
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
    // Ft CONSULTAR
    fastify.get('/get', async (solicitud, respuesta) => {
        respuesta.send(arrayUsuarios);
    });
    // GESTION DEL ARCHIVO POSTS
    async function leerPosts() {
        try {
            const datos = await fs.readFile('posts.json', 'utf-8');
            if (!datos.trim())
                return [];
            return JSON.parse(datos);
        }
        catch {
            return [];
        }
    }
    async function guardarPosts(arrayPosts) {
        await fs.writeFile('posts.json', JSON.stringify(arrayPosts, null, 2));
    }
    let arrayPosts = await leerPosts();
    // CREAR POST (en html)
    // Esta función es identíca a crear nuevo usuario + post pero aquí especificas el usuario 
    // en  la URL y en el normal no
    fastify.post('/posts/:nombre', async (solicitud, respuesta) => {
        const nombrePosteador = solicitud.params.nombre;
        const { contenido } = solicitud.body;
        let id;
        // Aumentar en 1 el id por cada nuevo post
        if (arrayPosts.length === 0) {
            id = 1;
        }
        else {
            // sin los ? falla
            id = (arrayPosts[arrayPosts.length - 1]?.id ?? 0) + 1;
        }
        arrayPosts.push({ id, usuario: nombrePosteador, contenido });
        await guardarPosts(arrayPosts);
        respuesta.send('Post creado para el usuario ' + nombrePosteador);
    });
    // CONSULTAR POSTS
    fastify.get('/posts/:nombre', async (solicitud, respuesta) => {
        // Solicitud.params equivale a :nombre + es de tipo string
        // Extrae el nombre (.nombre) del parámetro del objeto recibido 
        // en la solicitud
        const nombreUsuario = solicitud.params.nombre;
        //Filtra los posts que pertenecen a este usuario
        const postsUsuario = arrayPosts.filter(post => post.usuario === nombreUsuario);
        respuesta.send(postsUsuario);
    });
    // BORRAR POST
    fastify.delete('/posts/:id', async (solicitud, respuesta) => {
        // 1. Extraigo el parámetro id de la solicitud
        const param_id = Number(solicitud.params.id);
        // 2. Busco el índice del post con ese id en el array
        const index = arrayPosts.findIndex(post => post.id === param_id);
        // 3. Si el post existe (índice != -1)
        if (index !== -1) {
            // 4. Elimina el post del array
            arrayPosts.splice(index, 1);
            // 5. Guarda el archivo con el array actualizado 
            await guardarPosts(arrayPosts);
        }
        else {
            respuesta.status(404).send('No existe ese post');
        }
    });
    /* ------------------------------------------------------------------
                                    LISTEN
    ------------------------------------------------------------------ */
    fastify.listen({ port: 3001 }, () => {
        console.log('API is listening');
    });
}
main();
//# sourceMappingURL=index.js.map