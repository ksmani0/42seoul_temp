FROM alpine:3.12

RUN apk update && apk upgrade
RUN apk add nginx
RUN apk add vim
RUN	apk	add	openssl
RUN apk add openssh

# Add user
RUN adduser -D -g 'www' www
RUN mkdir /www
RUN chown -R www:www /var/lib/nginx
RUN chown -R www:www /www

# Copy configure file in alpine linux
COPY nginx.conf etc/nginx/
COPY index.html /www/index.html

# create certificate and public key
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout etc/ssl/private/localhost.dev.key -out etc/ssl/certs/localhost.dev.crt

# open ports ssh, http, https
EXPOSE 22 80 443

# Add ssh user
RUN adduser -D 'mykang'
RUN echo 'mykang:mykang' | chpasswd

# Run nginx
RUN mkdir -p /run/nginx
#CMD ["nginx", "-g", "daemon off;"]
COPY run.sh /
ENTRYPOINT ["sh", "./run.sh"]
