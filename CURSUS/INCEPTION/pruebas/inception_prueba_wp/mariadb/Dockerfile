# Usa la imagen base oficial de MariaDB
FROM mariadb:10.5

# Configura las variables de entorno necesarias para MariaDB
ENV MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD}
ENV MYSQL_DATABASE=${MYSQL_DATABASE}
ENV MYSQL_USER=${MYSQL_USER}
ENV MYSQL_PASSWORD=${MYSQL_PASSWORD}

# Exponer el puerto 3306 para MariaDB
EXPOSE 3306