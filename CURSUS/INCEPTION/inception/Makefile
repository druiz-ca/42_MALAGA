#crea los directorios para almacenar los datos persistentes
# ejecuta up (crear imágenes) y build (levantar los contenedores) del docker-compose
all:
	@mkdir -p ~/data 
	@mkdir -p ~/data/database ~/data/wordpress
	@docker-compose -f ./srcs/docker-compose.yml up -d --build

# Detiene y elimina los contenedores, redes, recursos, etc
down:
	docker-compose -f ./srcs/docker-compose.yml down


re: stop all

# Entra dentro del contenedor mariadb y ejecuta bash para ejecutar comandos dentro del SO del contenedor
mariadb:
	docker exec -it mariadb /bin/bash

# Entra dentro del contenedor WP y ejecuta bash para ejecutar comandos dentro del SO del contenedor
wordpress:
	docker exec -it wordpress /bin/bash

# Entra dentro del contenedor nginx y ejecuta bash para ejecutar comandos dentro del SO del contenedor
nginx:
	docker exec -it nginx /bin/bash

# Borra los volumenes creados
clean:
	docker volume rm DataBase WordPress

# stop (detiene los contenedores en ejecución), rm (los elimina), rmi -f (borra las imágenes), volume rm (borra volumenes), elimina redes 
fclean:
	docker stop $$(docker ps -qa); docker rm $$(docker ps -qa); docker rmi -f $$(docker images -qa); docker volume rm $$(docker volume ls -q); docker network rm $$(docker network ls -q) 2>/dev/null

# Borra todo el cache
fclean_cache:
	docker system prune -a --volumes

# vuelve a crear las imágenes y a levnatar contenedores (force para obligarlo aunque no hayan habido cambios)
recreate:
		docker-compose -f ./srcs/docker-compose.yml up -d --build --force-recreate

.PHONY: stop clean re all
