FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add vim

# install nginx
RUN apk add nginx

# install phpmyadmin
RUN apk add php7 php7-fpm lighttpd php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom php7-mbstring php7-session
RUN wget http://files.directadmin.com/services/all/phpMyAdmin/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN tar zxvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN rm phpMyAdmin-5.0.2-all-languages.tar.gz
RUN mv phpMyAdmin-5.0.2-all-languages phpmyadmin

# make dir for start nginx, nginx.pid
RUN mkdir -p /run/nginx

# open port 5000
EXPOSE 5000

# copy configure file
#COPY nginx.conf etc/nginx
COPY config.inc.php phpmyadmin
COPY default.conf etc/nginx/conf.d/default.conf
COPY run.sh /

# test openrc
RUN apk add openrc

# run nginx
#ENTRYPOINT ["nginx", "-g", "daemon off;"]
#ENTRYPOINT ["nginx", "-g", "daemon off;"]
ENTRYPOINT ["sh", "run.sh"]
