
# Variables
DOCKER_COMPOSE = docker-compose
COMPOSE_FILE = docker-compose.yml

# Construye las imágenes de Docker definidas en el archivo docker-compose.yml
build:
# el -f indica que se usará el archivo docker-compose.yml
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) build

# Levantar los servicios
up:
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) up -d

# Detener los servicios
down:
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) down

# Limpiar los contenedores, imágenes y volúmenes
clean:
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) down --rmi all --volumes --remove-orphans

# Reiniciar los servicios
restart: down up