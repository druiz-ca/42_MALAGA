DOCKER_COMPOSE = docker-compose
COMPOSE_FILE = docker-compose.yml

build:
# el -f indica que se usará el archivo docker-compose.yml
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) build

up:
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) up -d

down:
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) down

clean:
	$(DOCKER_COMPOSE) -f $(COMPOSE_FILE) down --rmi all --volumes --remove-orphans

restart: down up