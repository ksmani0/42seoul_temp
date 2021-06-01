FROM alpine:3.12.0

RUN apk --update --no-cache add nginx
RUN mkdir -p /run/nginx; mkdir -p /var/www

RUN apk --update --no-cache add php7-fpm php7-common php7-iconv php7-json \
	php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo \
	php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext \
	php7-ldap php7-ctype php7-dom mysql-client

RUN wget https://wordpress.org/latest.tar.gz
RUN tar -zxvf latest.tar.gz && \
	rm -f latest.tar.gz && \
	mv wordpress/ /var/www/ && \
	chmod -R 777 /var/www/*

COPY wp-config.php /var/www/wordpress/
COPY default.conf /etc/nginx/conf.d/
COPY wordpress.sql /
COPY wordpress_setup.sh /

#Port number requested in the assignment.
EXPOSE 5050

ENTRYPOINT  ["sh", "wordpress_setup.sh"]
