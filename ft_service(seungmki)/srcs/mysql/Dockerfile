#setup.sh: docker build -t ft_services-mysql srcs/mysql >> logs.txt
FROM alpine:3.12.0

#Even if you update to the latest version, the index of the package is not stored locally.
#You can keep your Docker container light.
RUN apk update && \
	apk --update --no-cache add \
	mysql mysql-client

COPY ./mysql_setup.sh /usr/sbin/mysql_setup.sh
RUN chmod +x /usr/sbin/mysql_setup.sh
#Grant execute permission to all users.

COPY my.cnf /etc/my.cnf
RUN chmod 644 /etc/my.cnf

#port 3306 for mysql
EXPOSE 3306

ENTRYPOINT ["/usr/sbin/mysql_setup.sh"]
