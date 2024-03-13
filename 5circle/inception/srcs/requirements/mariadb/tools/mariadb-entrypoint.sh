#!/bin/bash
set -e

mkdir -p /var/lib/mysql /var/run/mysqld
chown -R mysql:mysql /var/lib/mysql /var/run/mysqld
chmod 777 /var/run/mysqld

# mysqld(루트권한 설정 명령어) 포그라운드 실행
mysqld --user=root&

until mysqladmin ping -hlocalhost -uroot -p${MYSQL_ROOT_PASSWORD} > /dev/null 2>&1; do
    echo "Waiting for MariaDB to start..."
    sleep 1
done

#root계정 비밀번호 설정
#새로운 데이터베이스, 유저 생성(mariadb/sooyang)
#새로운 유저에게 데이터베이스의 모든 권한 부여 후 적용
mysql -uroot -p${MYSQL_ROOT_PASSWORD} <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF
#백그라운드에서 실행중인 루트계정 셧다운시킴 (한번 나갔다가 재실행 시켜야 완전히 적용됨)

mysqladmin -uroot -p${MYSQL_ROOT_PASSWORD} shutdown
exec mysqld --user=mysql