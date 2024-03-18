FROM debian:bullseye

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get -y install nginx openssl

COPY ./conf/nginx.conf /etc/nginx/sites-available/default

RUN openssl req -x509 -nodes \
	-days 365 \
	-newkey rsa:4096 \
	-keyout /etc/ssl/private/sooyang.key \
	-out /etc/ssl/certs/sooyang.crt \
	-subj "/C=KO/ST=Seoul/L=Gaepodong/O=42seoul/OU=gam/CN=pppppark2@gmail.com"

EXPOSE 443

ENTRYPOINT [ "nginx", "-g", "daemon off;" ]