
# Usamos la imagen oficial de Nginx basada en Alpine (ligera)
FROM nginx:alpine

# Copia el archivo index.html al directorio donde Nginx busca los archivos estáticos
COPY index.html /usr/share/nginx/html/index.html

# (Opcional) Se puede exponer el puerto 80,
# pero en este caso docker-compose se encargará del mapeo de puertos.
EXPOSE 80