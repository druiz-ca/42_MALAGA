Nombre de la asignación: mini_serv
Archivos esperados: mini_serv.c
Funciones permitidas: write, close, select, socket, accept, listen, send, recv, bind, strstr, malloc, realloc, free, calloc, bzero, atoi, sprintf, strlen, exit, strcpy, strcat, memset
--------------------------------------------------------------------------------

Escriba un programa que escuche si el cliente se conecta a un puerto específico en 127.0.0.1 y permita que los clientes se comuniquen entre sí.

Este programa tomará como primer argumento el puerto al que se vinculará.

Si no se proporciona ningún argumento, debe escribir en la salida estándar "Número incorrecto de argumentos" seguido de \n y salir con el estado 1.

Si una llamada al sistema devuelve un error antes de que el programa comience a aceptar la conexión, debe escribir en la salida estándar "Error fatal" seguido de \n y salir con el estado 1.

Si no se puede asignar memoria, debe escribir en la salida estándar "Error fatal" seguido de \n y salir con el estado 1. Error" seguido de \n y salida con estado 1.

Su programa debe ser no bloqueante, pero el cliente puede ser perezoso y, si no lee su mensaje, NO debe desconectarlo.

Su programa no debe contener #define preproc.
Su programa solo debe escuchar la red 127.0.0.1.
El fd que recibirá ya estará configurado para bloquear 'recv' o 'send' si no se ha llamado a select antes de llamarlos, pero no se bloqueará en caso contrario.

Cuando un cliente se conecta al servidor:
- Se le asignará un ID. El primer cliente recibirá el ID 0 y cada nuevo cliente recibirá el ID del último cliente + 1.
- %d se reemplazará por este número.
- Se envía un mensaje a todos los clientes conectados al servidor: "servidor: cliente %d acaba de llegar\n".

Los clientes deben poder enviar mensajes a su programa. 
- El mensaje solo tendrá caracteres imprimibles, no es necesario comprobarlo.
- Un solo mensaje puede contener varios \n.
- Cuando el servidor recibe un mensaje, debe reenviarlo a todos los demás clientes con "cliente %d:" antes de cada línea.

Cuando un cliente se desconecta del servidor:
- Se envía un mensaje a todos los clientes que estaban conectados al servidor: "servidor: cliente %d acaba de salir\n".

Se prohíben las fugas de memoria o de memoria flash.

Para ayudarte, encontrarás el archivo main.c con el inicio de un servidor y quizás algunas funciones útiles. (Ten cuidado, este archivo utiliza funciones prohibidas o escribe cosas que no deben estar presentes en tu programa final).

Advertencia: nuestro equipo de pruebas espera que envíes los mensajes lo más rápido posible. No uses un búfer innecesario.

La evaluación puede ser un poco más larga de lo habitual...

Sugerencia: puedes usar nc para probar tu programa.
Sugerencia: deberías usar nc para probar tu programa.
Sugerencia: Para probar, puedes usar fcntl(fd, F_SETFL, O_NONBLOCK), pero usa select y NUNCA marques EAGAIN (man 2 send).