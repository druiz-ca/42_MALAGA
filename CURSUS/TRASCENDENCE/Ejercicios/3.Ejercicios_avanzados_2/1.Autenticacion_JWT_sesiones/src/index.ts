/* ----------------------------------------------------------------------
                            IMPORTS Y CONFIGURACIÓN
---------------------------------------------------------------------- */
import bcrypt from 'bcrypt';

const saltRounds = 10;
// Hasheado de contraseña
const hashedPassword = await bcrypt.hash(password_noHash, saltRounds);

// LOGIN Compara la contraseña recibida con el hash guardado
const match = await bcrypt.compare(password_noHash, usuario.password);
if(!match) return respuesta.status(401).send('Credenciales incorrectas');

