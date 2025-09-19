import Fastify from 'fastify';           // Importa el framework Fastify para crear el servidor web.
import cors from '@fastify/cors';

function esperar(ms: number) 
{
  return new Promise(resolve => setTimeout(resolve, ms));
}

async function demo() {
  console.log('Empieza');
  await esperar(2000); // Espera 2 segundos
  console.log('Han pasado 2 segundos');
}

demo();