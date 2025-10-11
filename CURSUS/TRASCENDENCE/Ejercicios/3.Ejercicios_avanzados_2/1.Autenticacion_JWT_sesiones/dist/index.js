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
        const token = jwt.sign({ nombre: checkUser.nombre, email: checkUser.email }, 'clave_secreta', { expiresIn: '1h' });
        // Enviar el token al Front en la respuesta
        res.send({ token });
    });
    fastify.listen({ port: 3000 }, () => {
        console.log('API is listening');
    });
}
main();
//# sourceMappingURL=index.js.map