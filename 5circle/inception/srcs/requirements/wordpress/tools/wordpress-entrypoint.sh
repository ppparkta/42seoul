#!/bin/bash
mkdir -p /var/www/html
chown -R www-data:www-data /var/www/html
cd /var/www/html
mkdir -p /run/php
wp core download --locale=ko_KR --allow-root

wp config create --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD --dbhost=mariadb --allow-root
wp core install --url="https://localhost" --admin_user="$WP_ADMIN_NAME" --admin_password="$WP_ADMIN_PASSWORD" --admin_email="$WP_ADMIN_EMAIL" --skip-email --title="$WP_TITLE" --allow-root
wp user create "$WP_USER_NAME" "$WP_USER_EMAIL" --user_pass="$WP_USER_PASSWORD" --allow-root

exec php-fpm7.4 -F
