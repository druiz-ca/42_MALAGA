FROM debian:bullseye
RUN apt update -y && apt upgrade -y

# Instala WGET: para descargar archivos, TAR: para descomprimir archivos, CURL: para transferencia de datos
RUN apt install wget -y && apt install tar -y && apt install curl -y

# Instala PHP-FPM y la extensión de PHP para mysql para ejecutar wordpress
RUN apt install -y php-fpm php-mysql

# crea un directorio donde se alojará el código de WP
RUN mkdir -p /var/www/html

# Descarga la ultima version de WP comprimida
RUN wget -O /tmp/wordpress.tar.gz https://wordpress.org/latest.tar.gz

# Descomprime el tar en el directorio ...html y elimina el .tar
RUN tar -xzf /tmp/wordpress.tar.gz -C /var/www/html && rm /tmp/wordpress.tar.gz

# Instala el cliente de maridb par que WP pueda conectarse
RUN apt install -y mariadb-client

# copia el .sh a la raiz del contenedor
COPY wp_init.sh /

# usará el puerto 9000 (x defecto de PHP-FPM)
EXPOSE 9000

# comando que ejecutará cuando inice el contendor
CMD ["sh", "wp_init.sh"]
