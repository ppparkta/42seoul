#!/bin/bash
mkdir -p /var/www/html
chown -R www-data:www-data /var/www/html
cd /var/www/html
mkdir -p /run/php

wp core download --locale=ko_KR --force --allow-root
wp config create --dbname="$MYSQL_DATABASE" --dbuser="$MYSQL_USER" --dbpass="$MYSQL_PASSWORD" --dbhost=mariadb --allow-root
wp core install --url="https://localhost" --admin_user="$WORDPRESS_ADMIN_NAME" --admin_password="$WORDPRESS_ADMIN_PASSWORD" --admin_email="$WORDPRESS_ADMIN_EMAIL" --skip-email --title="$WORDPRESS_TITLE" --allow-root
wp user create "$WORDPRESS_USER_NAME" "$WORDPRESS_USER_EMAIL" --user_pass="$WORDPRESS_USER_PASSWORD" --allow-root
wp theme activate twentytwentytwo --allow-root

exec php-fpm7.4 -F
