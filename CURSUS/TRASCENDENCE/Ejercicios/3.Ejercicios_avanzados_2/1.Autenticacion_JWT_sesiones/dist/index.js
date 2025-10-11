import * as bcrypt from 'bcrypt';
const password = 'miContraseñaSegura';
const saltRounds = 10;
// Hashear la contraseña
bcrypt.hash(password, saltRounds, function (err, hash) {
    // Guardar 'hash' en la base de datos
    console.log(hash);
});
//# sourceMappingURL=index.js.map