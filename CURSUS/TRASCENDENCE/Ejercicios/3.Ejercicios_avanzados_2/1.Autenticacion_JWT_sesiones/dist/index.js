/* ----------------------------------------------------------------------
                            IMPORTS Y CONFIGURACIÓN
---------------------------------------------------------------------- */
import Fastify from 'fastify';
import cors from '@fastify/cors';
import bcrypt from 'bcrypt';
import { promises as fs } from 'fs';
import jwt from 'jsonwebtoken';
async function main() {
    const fastify = Fastify();
    await fastify.register(cors, {
        methods: ['GET', 'POST', 'DELETE', 'PUT']
    });
    async function leerUsuarios() {
        const datos = await fs.readFile('usuarios.json', 'utf-8');
        return JSON.parse(datos);
    }
    async function guardarUsuarios(arrayUsuarios) {
        await fs.writeFile('usuarios.json', JSON.stringify(arrayUsuarios, null, 2));
    }
    let arrayUsuarios = await leerUsuarios();
    fastify.post('/register', async (req, res) => {
        const { nombre, email, password } = req.body;
        // Validar duplicados...
        const existe = arrayUsuarios.find(u => u.email === email || u.nombre === nombre);
        if (existe)
            return res.status(400).send('Ya existe');
        // Hashear el password
        const hashedPassword = await bcrypt.hash(password, 10);
        // Guardar usuario con hashedPassword
        arrayUsuarios.push({ nombre, email, password: hashedPassword });
        await guardarUsuarios(arrayUsuarios);
        //Envíamos mensaje de confirmación
        res.send('Usuario registrado');
    });
    fastify.post('/login', async (req, res) => {
        const { email, password } = req.body;
        // Comprobar que el usuario (x mail) exista
        const checkUser = arrayUsuarios.find(u => u.email === email);
        if (!checkUser)
            return res.status(400).send('No existe');
        // Comparar el password recibido con el hasheado
        const match = await bcrypt.compare(password, checkUser.password);
        if (!match)
            return res.status(401).send('Contraseña incorrecta');
        // Generar un JWT con los datos del ususario (menos el pass)
        const token = jwt.sign({ nombre: checkUser.nombre, email: checkUser.email }, 'clave_secreta', // clave con la que se firma el token
        { expiresIn: '1h' } // el token caduca en 1 hora
        );
        // Enviar el token al Front en la respuesta y este lo almacena
        //en localStorage
        res.send({ token });
    });
    // (Equivalente al middelware)
    // Verifica q el user que hace la petición tiene un token válido
    function verificarJWT(req, res) {
        // Lee el token de la cabecera
        const auth = req.headers['authorization'];
        // sino tiene token : mensaje no autroizado
        if (!auth) {
            res.status(401).send('No autorizado');
            return null;
        }
        try {
            // Si el token es correcto devuelve los datos q contiene
            const decoded = jwt.verify(auth, 'clave_secreta');
            return decoded;
            // Si el token es incorrecto mensaje de error
        }
        catch {
            res.status(401).send('Token inválido');
            return null;
        }
    }
    // Ruta accesible solo a user autenticados
    fastify.get('/profile', async (req, res) => {
        // Verifica el token
        const usuario = verificarJWT(req, res);
        if (!usuario)
            return;
        // si es correcto devuelve los datos del usuario
        res.send({ mensaje: 'Perfil privado', usuario });
    });
    fastify.listen({ port: 3000 }, () => {
        console.log('API is listening');
    });
}
main();
//# sourceMappingURL=index.js.map