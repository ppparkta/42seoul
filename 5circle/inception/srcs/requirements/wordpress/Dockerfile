FROM debian:bullseye

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install -y vim sudo wget curl tar && \
	apt-get install -y mariadb-client php7.4-fpm php-mysql php-cli
	
COPY ./tools/wordpress-entrypoint.sh /wordpress-entrypoint.sh
COPY ./conf/ /

RUN chmod +x /wordpress-entrypoint.sh

EXPOSE 9000

ENTRYPOINT ["sh","/wordpress-entrypoint.sh"]