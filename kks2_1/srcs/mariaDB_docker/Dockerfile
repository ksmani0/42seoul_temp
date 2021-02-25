FROM alpine:3.12

RUN apk update
RUN apk add vim
RUN apk add mariadb mariadb-client
RUN apk add nginx

# 해당 directory 를 생성하므로써 절대경로를 붙여줄 필요강 없다.
RUN mkdir -p /run/mysqld

# Initialization and start MariaDB deamon
#RUN mysql_install_db --user=mysql --datadir=/var/lib/mysql
#RUN mysqld_safe --datadir='/var/lib/mysql'
COPY run.sh .
COPY init_mysql.sql .
COPY my.cnf /etc

# open port 3306
EXPOSE 3306

# start script
ENTRYPOINT ["sh", "run.sh"]
#CMD sh run.sh
#RUN sh run.sh
