FROM debian:bullseye
RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get -y install mariadb-server
COPY ./conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
COPY ./tools/mariadb-entrypoint.sh /mariadb-entrypoint.sh
RUN chmod +x /mariadb-entrypoint.sh
EXPOSE 3306
ENTRYPOINT ["sh", "/mariadb-entrypoint.sh"]