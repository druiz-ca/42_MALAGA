import Fastify from 'fastify';           // Importa el framework Fastify para crear el servidor web.
import cors from '@fastify/cors';         // Importa el plugin CORS para permitir peticiones de otros orígenes.


async function main()
{
  const fastify = Fastify();

  fastify.post('prueba_post', () => {
  
    
  });

  fastify.get('/prueba', (request, reply) => 
  {
    reply.send({ok:true});
  });

  fastify.get('/health', (request, reply) => 
  {
    reply.send({status : 'ok'});
  });

  fastify.listen({port:3001},() => 
  {
      console.log('funciona');
  });
}


main();