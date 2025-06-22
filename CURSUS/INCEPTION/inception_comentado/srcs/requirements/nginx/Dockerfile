FROM debian:bullseye
RUN apt update -y && apt upgrade -y

# instala el servidor web nginx y la herramineta openssl para generar certidficado ssl
RUN apt install nginx -y && apt install openssl -y
RUN mkdir -p /etc/nginx/ssl

# Genra un certificado ssl(inception.crt) y su clave privada (inception.key)
   # usando openssl con los datos de -subj: (para que sirva contenido por HTTPS)
RUN openssl req -x509 -nodes \
    -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key \
    -subj "/C=ES/ST=Andalucia/L=Malaga/O=42/OU=42/CN=druiz-ca.42.fr/UID=druiz-ca"

# Copia el archivo de configuración al contenedor
COPY conf/nginx.conf /etc/nginx/nginx.conf

# Indica el puerto de conexión estándar del contenedor para conexiones HTTPS
EXPOSE 443

# El comando que ejecutará cuando el contenedor esté iniciado
   # ejecuta nginx en primer plano (sin convertirse en demonio) para que el contenedor siga activo
      # Un demonio es un programa que se ejecuta en segundo plano sin necesidad de usar una terminal ni tener
      # una sesión de usuario iniciada.
      # Por defecto nginx al ejecutarse se intenta convertir en demonio (para correr en segundo plano)
      # daemon off: le indica que no se convierta en demonio y que nginx siga en primer plano
CMD ["nginx", "-g", "daemon off;"]
