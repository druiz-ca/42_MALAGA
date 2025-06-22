FROM debian:bullseye 

# Actualiza los paquetes disponibles y luego actualiza los instalados a sus ultimas versiones
    # el -y es para que responda "SI" a cualquier pregunta que surga en el proceso
RUN apt update -y && apt upgrade -y

# Instala el servidor de bases de datos mariadb
RUN apt install mariadb-server -y

# Copia el archivo de configuración al contenedor de maridb
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Copia un script de inicialización a la raiz del contenedor para configurar la base de datos
COPY tools/mariadb_init.sh /

# Indica que el contenedor escuchará en el puerto 3306 (x defecto para mariadb) aunque lo lo abre
EXPOSE 3306

# Define el comando que se ejecutará cuando inicie el contenedor
CMD ["bash", "mariadb_init.sh"]
