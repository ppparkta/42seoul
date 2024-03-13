FROM debian:bullseye

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get -y install mariadb-client php7.4-fpm php-mysql php-cli && \
	apt-get -y vim sudo wget curl tar 

COPY ./tools/wordpress-entrypoint.sh /wordpress-entrypoint.sh

RUN chmod +x /wordpress-entrypoint.sh

EXPOSE 9000

ENTRYPOINT ["sh","/wordpress-entrypoint.sh"]