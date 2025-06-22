
# Indica que el script debe ejecutarse con el intérprete de comandos sh
#!/bin/sh

touch init.sql

# Crea directorios para que mariadb pueda almacenar archivos de ejecución y sockets(-p evita errores)
mkdir -p /run/mysqld
mkdir -p /var/run/mysqld

# Estas lineas escriben comandos SQL en el archivo init.sql
echo "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;" >> init.sql
echo "CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';" >> init.sql
echo "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO '${SQL_USER}'@'%';" >> init.sql
echo "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';" >> init.sql
echo "FLUSH PRIVILEGES;" >> init.sql

# cambia los permisos a todos los usuarios de acceso total
chmod 777 init.sql

# Mueve el archivo al directorio
mv init.sql /run/mysqld/init.sql

# Cambia el propietario del directorio al usuario mysql y al grupo root (ch= change, own= propietario)
chown -R mysql:root /var/run/mysqld

# Inicia el servidor mariadb e indica que ejecute los comandos del archivo init
mariadbd --init-file /run/mysqld/init.sql
