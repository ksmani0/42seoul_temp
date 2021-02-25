# first step
FROM	alpine:3.12

RUN		apk update && apk upgrade
RUN		apk add nginx
RUN		apk add openrc
RUN		apk add vim
# install php-fpm
RUN apk add php7 php7-fpm lighttpd php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom php7-mbstring php7-session

# set nginx.pid
RUN mkdir -p run/nginx
# install wordpress
RUN		apk add wget
RUN		wget http://wordpress.org/latest.tar.gz
RUN		tar -xvf latest.tar.gz

# copy wordpress configuration file
COPY	wp-config.php wordpress/
# Copy wordpress DB configure file
COPY	nginx.conf	etc/nginx
# copy run script file
COPY	run.sh /

EXPOSE	5050

# run
ENTRYPOINT ["sh", "run.sh"]
