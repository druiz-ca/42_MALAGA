all:
	@mkdir -p ~/data
	@mkdir -p ~/data/database ~/data/wordpress
	@docker-compose -f ./srcs/docker-compose.yml up -d --build
down:
	docker-compose -f ./srcs/docker-compose.yml down
re: stop all
mariadb:
	docker exec -it mariadb /bin/bash
wordpress:
	docker exec -it wordpress /bin/bash
nginx:
	docker exec -it nginx /bin/bash
clean:
	docker volume rm DataBase WordPress
fclean:
	docker stop $$(docker ps -qa); docker rm $$(docker ps -qa); docker rmi -f $$(docker images -qa); docker volume rm $$(docker volume ls -q); docker network rm $$(docker network ls -q) 2>/dev/null

fclean_cache:
	docker system prune -a --volumes

recreate:
		docker-compose -f ./srcs/docker-compose.yml up -d --build --force-recreate

.PHONY: stop clean re all
