NAME = inception

VOLUME_PATH		:= /home/sooyang/data

all		:	$(NAME)

$(NAME)	:
	@sudo mkdir -p $(VOLUME_PATH)/DB/
	@sudo mkdir -p $(VOLUME_PATH)/wordpress/
	@docker-compose -f ./srcs/docker-compose.yml up --build -d

up		:
	@docker-compose -f ./srcs/docker-compose.yml up -d

down	:
	@docker-compose -f ./srcs/docker-compose.yml down

clean	:
	@docker-compose -f ./srcs/docker-compose.yml down --rmi all --volumes

fclean	: clean
	@docker system prune -af
	@sudo rm -rf $(VOLUME_PATH)

re	: fclean all

.PHONY	: all down clean fclean re