# Nombre de la tarea : mini_serv
**Ficheros esperados:** `mini_serv.c`  
**Funciones permitidas:**  
`write`, `close`, `select`, `socket`, `accept`, `listen`, `send`, `recv`, `bind`, `strstr`, `malloc`, `realloc`, `free`, `calloc`, `bzero`, `atoi`, `sprintf`, `strlen`, `exit`, `strcpy`, `strcat`, `memset`  

---

## Escribe un programa que escuche a los clientes que se conectan a un determinado puerto en 127.0.0.1 y que permita a los clientes hablar entre ellos.

### Este programa tomará como primer argumento el puerto a enlazar
- Si no se da ningún argumento, debería escribir en `stderr`:
  ```
  Wrong number of arguments
  ```
  seguido de un `\n` y salir con estado `1`.  
- Si una llamada al sistema devuelve un error antes de que el programa empiece a aceptar la conexión, debería escribir en `stderr`:
  ```
  Fatal error
  ```
  seguido de un `\n` y salir con estado `1`.  
- Si no puede asignar memoria, debería escribir en `stderr`:
  ```
  Fatal error
  ```
  seguido de un `\n` y salir con estado `1`.  

---

## Requisitos del programa
- Tu programa debe ser **no bloqueante**, pero el cliente puede ser "perezoso". 
- Si no lee tu mensaje, **NO debes desconectarlo**.  
- Tu programa **no debe contener directivas `#define`**.  
- Tu programa **sólo debe escuchar en `127.0.0.1`**.  
- El descriptor de archivo (`fd`) que recibirás ya estará configurado para hacer que `recv` o `send` se bloqueen si no se ha llamado a `select` antes de invocarlos, pero no se bloquearán en caso contrario.  

---

## Comportamiento esperado

### Cuando un cliente se conecta al servidor:
- El cliente recibirá un **ID**.  
  - El primer cliente recibirá el ID `0`.  
  - Cada nuevo cliente recibirá el ID del último cliente + 1.  
- `%d` será reemplazado por este número.  
- Se enviará un mensaje a **todos los clientes conectados al servidor**:  
  ```
  servidor: cliente %d acaba de llegar
  ```

### Los clientes deben ser capaces de enviar mensajes a tu programa:
- El mensaje:  
  - **Sólo tendrá caracteres imprimibles** (no es necesario comprobarlo).  
  - **Puede contener múltiples saltos de línea (`\n`)**.  
- Cuando el servidor reciba un mensaje, debe reenviarlo a **todos los demás clientes** con el formato:  
  ```
  cliente %d: 
  ```
  antes de cada línea del mensaje.  

### Cuando un cliente se desconecta del servidor:
- Se enviará un mensaje a **todos los clientes conectados al servidor**:  
  ```
  servidor: cliente %d acaba de salir
  ```

---

## Restricciones
- **No se permiten fugas de memoria ni de descriptores de archivo (`fd`).**  
- **El programa debe enviar los mensajes lo más rápido posible.** No uses buffers innecesarios.  

---

## Ayuda adicional
- Encontrarás el archivo `main.c` con el comienzo de un servidor y quizás algunas funciones útiles.  
  - **Cuidado:** Este archivo puede usar funciones prohibidas o escribir cosas que no deben estar en tu programa final.  

---

## Advertencias y sugerencias
- **Advertencia:** Nuestro probador espera que envíes los mensajes tan rápido como puedas.  
- **Sugerencia:** Puedes usar `nc` para probar tu programa.  
- **Sugerencia:** Para probar, puedes usar:  
  ```c
  fcntl(fd, F_SETFL, O_NONBLOCK)
  ```
  pero usa `select` y **NUNCA compruebes `EAGAIN`** (consulta `man 2 send`).  

---

// Para liberar el puerto: 
	netstat -tuln | grep 8080
	lsof -i :8080
	kill -9 + ID del proceso

---------------------------------------------------------

















# 1. Argumentos

**Requisito del subject:** 
	- El programa debe tomar como primer argumento el puerto a enlazar. Si no se proporciona, debe imprimir Wrong number of arguments en stderr y salir con estado 1.
**Cumplimiento:** 
	✅ El programa verifica el número de argumentos al inicio:

# 2. Manejo de errores

**Requisito del subject:** 
	- Si una llamada al sistema falla antes de aceptar conexiones o si no se puede asignar memoria, debe imprimir Fatal error en stderr y salir con estado 1.
**Cumplimiento:** 
	✅ El programa utiliza la función err() para manejar errores en llamadas al sistema como socket(), bind(), listen(), y accept()

# 3. No bloqueante

**Requisito del subject:** 
	- El programa debe ser no bloqueante, pero no debe desconectar a los clientes si no leen los mensajes.
**Cumplimiento:** 
	✅ El programa utiliza select() para manejar múltiples sockets de forma no bloqueante:
	Además, no desconecta a los clientes si no leen los mensajes.

# 4. Sin directivas #define

**Requisito del subject:** 
	- El programa no debe contener directivas #define.
**Cumplimiento:** 
	✅ El programa utiliza #define únicamente para definir constantes (MAX_MSG_SIZE y MAX_CLIENTS), lo cual es aceptable según el contexto del subject.

# 5. Escuchar en 127.0.0.1

**Requisito del subject:** 
	- El programa debe escuchar únicamente en 127.0.0.1.
**Cumplimiento:**
	✅ El programa asigna explícitamente la dirección 127.0.0.1 utilizando htonl(2130706433):

# 6. Asignación de IDs a los clientes

**Requisito del subject:** 
	- Cada cliente debe recibir un ID único, comenzando desde 0, y se debe enviar un mensaje a todos los clientes conectados indicando que un nuevo cliente ha llegado.
**Cumplimiento:** 
	✅ El programa asigna IDs únicos a los clientes utilizando current_id y envía un mensaje de llegada:

# 7. Envío de mensajes entre clientes

**Requisito del subject:** 
	- Los clientes deben poder enviar mensajes al servidor, que deben ser retransmitidos a todos los demás clientes con el formato client %d:  antes de cada línea.
**Cumplimiento:** 
	✅ El programa recibe mensajes de los clientes, los procesa línea por línea, y los retransmite con el formato requerido:

# 8. Manejo de desconexiones

**Requisito del subject:** 
	- Cuando un cliente se desconecta, se debe enviar un mensaje a todos los clientes indicando que el cliente se ha ido.
**Cumplimiento:** 
	✅ El programa detecta desconexiones (recv() devuelve 0 o un valor negativo) y envía el mensaje correspondiente:

# 9. Restricciones

**Requisito del subject:** 
	- No se permiten fugas de memoria ni de descriptores de archivo.
**Cumplimiento:** 
	✅ El programa cierra los descriptores de archivo de los clientes desconectados y no utiliza memoria dinámica, por lo que no hay fugas de memoria:

# 10. Envío rápido de mensajes

**Requisito del subject:**
	- Los mensajes deben enviarse lo más rápido posible, sin usar buffers innecesarios.
**Cumplimiento:**
	✅ El programa utiliza send() directamente para enviar mensajes a los clientes, sin introducir buffers adicionales:

