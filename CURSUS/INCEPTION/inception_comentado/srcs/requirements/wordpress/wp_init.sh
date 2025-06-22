#!/bin/bash

# Detecta la versión de PHP instalada y la guarad en la variable PHP VERSION
PHP_VERSION=$(php -r "echo PHP_MAJOR_VERSION . '.' . PHP_MINOR_VERSION;")

# crea el directorio para los sockets de PHP
   # socket: archivo (...sock) que sirve para que se comuniquen los contenedores entre si sin usar la red
mkdir -p /run/php

# Cambia el propietario de los archivos de Wp al usuario y grupo www-data (que es el que usa el servidor web)
chown -R www-data.www-data /var/www/html/wordpress

# cambia los permisos para quye el prop pueda escribir y todos puedan leer y ejecutar
chmod -R 755 /var/www/html/wordpress

# Modifica el archivo de configuracion de PHP para que, en vez de usar un socket, escuche en el puerto 9000
   # con el nombre de host worspress
sed -i "s#listen = /run/php/php${PHP_VERSION}-fpm.sock#listen = wordpress:9000#g" /etc/php/${PHP_VERSION}/fpm/pool.d/www.conf

# se Mueve al directorio bin
cd /usr/local/bin/

# Descarga wp-cli (herramienta de linea de comandos para WP)
curl -fsSL https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar -o /usr/local/bin/wp

# le da permisos de ejecución
chmod +x /usr/local/bin/wp

# se mueve al directorio wordpress
cd /var/www/html/wordpress

# Crea el archivo de configuración wp-config.php con los datos de la base de datos y la URL
wp config create --allow-root   --dbname=$SQL_DATABASE \
                                --dbuser=$SQL_USER \
                                --dbpass=$SQL_PASSWORD \
                                --dbhost=mariadb:3306 \
				                        --url=$WP_URL \
                                --path='/var/www/html/wordpress'


# Instala WP con el usuario administrador, contraseña, etc
wp core install --allow-root    --url=$WP_URL \
                                --title=$WP_TITLE \
                                --admin_user=$WP_ADMIN_USR \
                                --admin_password=$WP_ADMIN_PWD \
                                --admin_email=$WP_ADMIN_EMAIL \
                                --skip-email \
                                --locale=es_ES \
			                          --path='/var/www/html/wordpress'

# Comprueba si existe un usuario adicional(WP-USR) y muestra un mensaje, sino existe lo crea
if ! wp user get "$WP_USR" --allow-root > /dev/null 2>&1; then
  wp user create "$WP_USR" "$WP_EMAIL" \
    --role=author \
    --user_pass="$WP_PWD" \
    --allow-root
else
  echo "🟡 user '$WP_USR' if exist."
fi

# Indica el proceso PHP en primer plano (-F) para mantener el contenedor en ejecución
php-fpm${PHP_VERSION} -F
