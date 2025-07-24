#!/bin/bash

# filepath: /path/to/test_server.sh

# Variables
SERVER_BINARY="./webserver" # Cambia esto por el nombre de tu ejecutable
CONFIG_FILE="./config.conf" # Cambia esto por la ruta de tu archivo de configuración
TEST_DIR="./test_files"     # Directorio para pruebas
PORT=8080                   # Puerto del servidor
HOST="localhost"
URL="http://$HOST:$PORT"

# Función para imprimir mensajes
print_message() {
    if [ $? -eq 0 ]; then
        echo -e "\e[32m[OK]\e[0m $1"
    else
        echo -e "\e[31m[ERROR]\e[0m $1"
    fi
}

# Inicia el servidor
echo "Iniciando el servidor..."
$SERVER_BINARY $CONFIG_FILE &
SERVER_PID=$!
sleep 2 # Espera para que el servidor se inicie

# Verifica que el servidor esté corriendo
if ps -p $SERVER_PID > /dev/null; then
    echo -e "\e[32m[OK]\e[0m Servidor iniciado correctamente (PID: $SERVER_PID)"
else
    echo -e "\e[31m[ERROR]\e[0m No se pudo iniciar el servidor"
    exit 1
fi

# Prueba 1: Verificar GET
curl -s -o /dev/null -w "%{http_code}" "$URL/test.html" | grep -q "200"
print_message "GET request funcionando correctamente"

# Prueba 2: Verificar POST
curl -s -X POST -d "name=Juan&age=30" "$URL/upload" | grep -q "200"
print_message "POST request funcionando correctamente"

# Prueba 3: Verificar DELETE
curl -s -X DELETE "$URL/test.html" | grep -q "200"
print_message "DELETE request funcionando correctamente"

# Prueba 4: Verificar subida de archivos
curl -s -F "file=@$TEST_DIR/test.txt" "$URL/upload" | grep -q "200"
print_message "Subida de archivos funcionando correctamente"

# Prueba 5: Verificar error 404
curl -s -o /dev/null -w "%{http_code}" "$URL/nonexistent.html" | grep -q "404"
print_message "Error 404 funcionando correctamente"

# Prueba 6: Verificar múltiples puertos
curl -s -o /dev/null -w "%{http_code}" "http://$HOST:8081/test.html" | grep -q "200"
print_message "Servidor escuchando en múltiples puertos"

# Prueba 7: Verificar CGI (PHP)
curl -s "$URL/cgi-bin/hello.php?name=Juan" | grep -q "<h1>Hello, Juan!</h1>"
print_message "CGI funcionando correctamente"

# Prueba 8: Verificar tamaño máximo del cuerpo
curl -s -X POST -d "$(head -c 100000 /dev/zero)" "$URL/upload" | grep -q "413"
print_message "Tamaño máximo del cuerpo funcionando correctamente"

# Prueba 9: Verificar conexión persistente (keep-alive)
curl -s -o /dev/null -w "%{http_code}" -H "Connection: keep-alive" "$URL/test.html" | grep -q "200"
print_message "Conexión persistente funcionando correctamente"

# Prueba 10: Verificar respuesta de error personalizada
curl -s -o /dev/null -w "%{http_code}" "$URL/error" | grep -q "500"
print_message "Páginas de error personalizadas funcionando correctamente"

# Detener el servidor
kill $SERVER_PID
echo "Servidor detenido."

exit 0