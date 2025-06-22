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

#
COPY conf/nginx.conf /etc/nginx/nginx.conf
EXPOSE 443
CMD ["nginx", "-g", "daemon off;"]
