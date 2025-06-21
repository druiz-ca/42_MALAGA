#!/bin/bash

---
- Este script prepara el entorno y automatiza la instalación de WordPress dentro del contenedor.
- Obtiene la versión instalada de PHP (por ejemplo, "7.4").
- Esto es útil si en el futuro se actualiza PHP y cambia la versión.

---

PHP_VERSION=$(php -r "echo PHP_MAJOR_VERSION . '.' . PHP_MINOR_VERSION;")

# Crea el directorio /run/php si no existe.
# Este directorio se usa para almacenar archivos de ejecución como el socket de PHP-FPM.
mkdir -p /run/php
# Si este directorio no existe, PHP-FPM no podrá crear o acceder al archivo de socket necesario, lo que causaría errores.

# Cambia el propietario de todos los archivos de WordPress a www-data (usuario y grupo).
# Esto es necesario para que el servidor web pueda leer y escribir los archivos de WordPress.
chown -R www-data.www-data /var/www/html/wordpress
# chown -> Cambia el propietario de archivos y directorios.
# -R -> Aplica el cambio de forma recursiva a todos los archivos y subdirectorios.
# www-data.www-data -> Usuario y grupo.
# /var/www/html/wordpress -> Carpeta donde están los archivos de WordPress.

# Cambia los permisos de los archivos de WordPress.
# 7 (rwx) para el propietario, 5 (r-x) para grupo y otros.
chmod -R 755 /var/www/html/wordpress
# 7 -> El propietario puede leer, escribir y ejecutar.
# 5 -> El grupo y otros pueden leer y ejecutar, pero no escribir.

# Modifica el archivo de configuración de PHP-FPM (www.conf) para que escuche en el puerto 9000 en vez de en un socket Unix.
# Por defecto, PHP-FPM usa un socket Unix para comunicarse.
# Aquí se cambia para que escuche en "wordpress:9000" (host:puerto).
sed -i "s#listen = /run/php/php${PHP_VERSION}-fpm.sock#listen = wordpress:9000#g" /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf
# sed -> Editor de flujo para modificar archivos de texto.
# -i -> Modifica el archivo directamente.
# s# -> Comando de sustitución.
# # -> Delimitador.
# g -> Bandera global, reemplaza todas las coincidencias en la línea.

### IMPORTANTE

# Desde aquí hay tres posibles soluciones para configurar WordPress:

# - Puedes renombrar el wp-config-sample.php a wp-config.php y modificarlo manualmente con "sed -i"
# - Puedes instalar wp-cli para crear el wp-config.php con comandos.
# - Puedes escribir un wp-config.php y copiarlo con el Dockerfile dentro del contenedor.

# Pero necesitarás instalar wp-cli de todas formas para la instalación de WordPress,
# y es la herramienta más eficiente en la mayoría de los casos para gestionar WordPress en scripts,
# así que elijo la segunda opción.

###

# WP-CLI es una interfaz de línea de comandos para gestionar instalaciones de WordPress.
# Permite realizar muchas tareas administrativas sin necesidad de usar el panel web de WordPress.

# Descargamos wp-cli en el directorio /usr/local/bin, que es donde suelen ir las aplicaciones externas.
cd /usr/local/bin

# Descargamos wp-cli desde el repositorio de Github.
wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
# Un archivo .phar es un tipo de archivo comprimido usado para empaquetar aplicaciones o librerías PHP en un solo ejecutable.

# Cambiamos el nombre del archivo descargado a "wp"
mv wp-cli.phar wp

# Damos permisos de ejecución al archivo
chmod +x wp

# Vamos al directorio donde debe estar el wp-config.php
cd /var/www/html/wordpress

# Este comando crea el archivo wp-config.php con nuestra configuración personalizada.
wp config create --allow-root   --dbname=$SQL_DATABASE \
                                --dbuser=$SQL_USER \
                                --dbpass=$SQL_PASSWORD \
                                --dbhost=mariadb:3306 \
                                --url=$WP_URL \
                                --path='/var/www/html/wordpress'
# wp config create -> Comando para crear el wp-config.php
# --allow-root -> Permite ejecutarlo como root (necesario en Docker).
# --dbname= -> Nombre de la base de datos.
# --dbuser= -> Usuario de la base de datos.
# --dbpass= -> Contraseña de la base de datos.
# --dbhost= -> Dirección del servidor de base de datos.
# --path= -> Ruta donde se creará el wp-config.php.

# Comando para instalar WordPress con la configuración inicial del sitio.
wp core install --allow-root    --url=$WP_URL \
                                --title=$WP_TITLE \
                                --admin_user=$WP_ADMIN_USR \
                                --admin_password=$WP_ADMIN_PWD \
                                --admin_email=$WP_ADMIN_EMAIL \
                                --skip-email \
                                --locale=es_ES \
                                --path='/var/www/html/wordpress'
# wp core install -> Comando para ejecutar la instalación principal de WordPress.
# --url= -> URL del sitio.
# --title= -> Título del sitio.
# --admin_user= -> Usuario administrador.
# --admin_password= -> Contraseña del administrador.
# --admin_email= -> Email del administrador.
# --skip-email -> No envía email de notificación.
# --locale=es_ES -> Idioma de la instalación.
# --path= -> Ruta de la instalación.

# Ahora creamos un usuario adicional por seguridad, para no usar siempre el admin.
wp user create $WP_USR $WP_EMAIL --role=author \
                                 --user_pass=$WP_PWD \
                                 --allow-root
# wp user create -> Comando para crear un nuevo usuario en WordPress.
# --role=author -> Rol del usuario (autor).
# --user_pass= -> Contraseña del usuario.

# Finalmente, ejecutamos PHP-FPM en primer plano para que el contenedor siga activo.
php-fpm${PHP_VERSION} -F
# Esto es necesario porque los contenedores Docker se detienen si el proceso principal termina.
# Ejecutar php-fpm en primer plano mantiene el contenedor en ejecución.