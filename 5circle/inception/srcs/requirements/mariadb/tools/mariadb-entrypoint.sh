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

#백그라운드에서 실행중인 루트계정 셧다운시킴 (한번 나갔다가 재실행 시키면 완전히 적용됨)
mysqladmin -uroot -p${MYSQL_ROOT_PASSWORD} shutdown
exec mysqld #--user=mysql