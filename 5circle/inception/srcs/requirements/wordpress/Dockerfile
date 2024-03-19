FROM debian:bullseye

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install -y vim sudo wget curl tar mariadb-client php7.4-fpm php-cli php-mysql

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp
    
COPY ./conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf
COPY ./tools/wordpress-entrypoint.sh /wordpress-entrypoint.sh

RUN chmod +x /wordpress-entrypoint.sh

EXPOSE 9000

ENTRYPOINT ["sh","/wordpress-entrypoint.sh"]