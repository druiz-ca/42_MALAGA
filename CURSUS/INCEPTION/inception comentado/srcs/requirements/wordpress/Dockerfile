# Usa la imagen base de Debian Bullseye
FROM debian:bullseye

# Actualiza la lista de paquetes e instala las últimas versiones
RUN apt update -y && apt upgrade -y

# Instala wget (descargar archivos) y tar (descomprimir archivos)
RUN apt install wget -y && apt install tar -y

# Instala PHP-FPM (para ejecutar PHP) y la extensión para conectar con MariaDB
RUN apt install -y php-fpm php-mysql

# Crea el directorio donde se alojará WordPress
RUN mkdir -p /var/www/html

# Descarga la última versión de WordPress y la guarda en /tmp
RUN wget -O /tmp/wordpress.tar.gz https://wordpress.org/latest.tar.gz

# Descomprime WordPress en /var/www/html y borra el archivo descargado
RUN tar -xzf /tmp/wordpress.tar.gz -C /var/www/html && rm /tmp/wordpress.tar.gz

# Instala el cliente de MariaDB para que WordPress pueda conectarse a la base de datos
RUN apt install -y mariadb-client

# Copia el script de inicialización de WordPress al contenedor
COPY wp_init.sh /

# Expone el puerto 9000 (usado por PHP-FPM)
EXPOSE 9000

# Al arrancar el contenedor, ejecuta el script wp_init.sh
CMD ["sh", "wp_init.sh"]
