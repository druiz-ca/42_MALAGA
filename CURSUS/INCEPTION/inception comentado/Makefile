all:
    # Create the directories for the volumes if they don't exists. 
	@mkdir -p ~/data
	@mkdir -p ~/data/database ~/data/wordpress

    # Runs docker compose in the background and rebuild images.
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

	# Muestro mensaje
	@echo "Inception is running"

# Removes the containers and volumes. Running docker compose up again will create the containers from scratch.
down:
    # etiene y elimina todos los contenedores, redes y volumenes
	docker-compose -f ./srcs/docker-compose.yml down

re: stop all
# falta stop, quitar

mariadb:
    # Access the mariadb container
	docker exec -it mariadb /bin/bash
        # exec: comando docker para ejecutar un comando dentro del contendor
        # bin/bash: comando a ajecutar( abrir una shell Bash)
          # se hace para ejecutar los comandos necesarios dentro del contenedor
        # it: interactiva, para poder escribir como si estuvieras dentro del contenedor (acceso directo)

wordpress:
    # Access the wordpress container
	docker exec -it wordpress /bin/bash

nginx:
    # Access nginx container
	docker exec -it nginx /bin/bash

clean:
    # Remove the volumes
	docker volume rm DataBase WordPress

# Run docker compose in the background and rebuild images and containers.
recreate:
    # Reconstruye y reinicia los contenedores y servicios ( añade force recreate)
	docker compose -f ./srcs/docker-compose.yml up -d --build --force-recreate

.PHONY: stop clean re all


# INDICE
# make all      --> Crea carpetas, construye y arranca los servicios
# make down     --> Detiene y elimina los contenedores y redes
# make clean    --> Borra los volúmenes de datos (base de datos y WordPress)
# make recreate --> Reconstruye y reinicia todo el entorno desde cero
# make mariadb  --> Accede al contenedor de MariaDB
# make wordpress--> Accede al contenedor de WordPress
# make nginx    --> Accede al contenedor de Nginx