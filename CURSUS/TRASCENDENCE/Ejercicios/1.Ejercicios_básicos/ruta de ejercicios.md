### 1. **Validación de datos**
- Haz que el POST rechace nombres vacíos o demasiado cortos.
- Devuelve un error si el nombre ya existe en el array.

### 2. **Guardar más información**
- Modifica el POST para aceptar y guardar también un email.
- Cambia el array para que cada usuario tenga `{ nombre, email }`.

### 3. **Obtener, actualiza y elimina un usuario concreto**
- Crea una ruta GET `/users/:nombre` que devuelva solo el usuario con ese nombre.
- Elimina un usuario concreto.
- Añade una ruta PUT `/users/:nombre` para actualizar el email de un usuario.

### 6. **Persistencia sencilla**
- Guarda el array de usuarios en un archivo JSON y recupéralo al arrancar el servidor (puedes usar `fs`).

### 7. **Pruebas con Postman**
- Aprende a usar Postman para probar tus endpoints de forma visual.

### 8. **Explora autenticación**
- Investiga cómo proteger rutas con una clave sencilla o un token.
