#!/bin/bash
mkdir -p /var/lib/mysql /var/run/mysqld
chmod 777 /var/lib/mysql /var/run/mysqld

mysqld&

until mysqladmin ping -hlocalhost -uroot > /dev/null 2>&1; do
    sleep 1
done

mysql -uroot <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

mysqladmin -uroot -p${MYSQL_ROOT_PASSWORD} shutdown
exec mysqld