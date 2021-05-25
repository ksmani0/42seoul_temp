#setup.sh: docker build -t ft_services-nginx srcs/nginx >> logs.txt
FROM alpine:3.12.0

#Install nginx and dependencies
#openssh includes openssh-server and openssh-cliet. Only openssh-server is used, so install only this.
RUN apk update && \
	apk --update --no-cache add \
	nginx openssl openssh-server

COPY ./index.html /var/www/index.html
COPY ./nginx_setup.sh /usr/sbin/nginx_setup.sh
RUN chmod +x /usr/sbin/nginx_setup.sh
COPY ./nginx.conf /etc/nginx/conf.d/
#Copying locally installed configuration files into the nginx container folder.

EXPOSE 80 443 22
#container port numbers setting
#port 22 for ssh

#ENTRYPOINT executes a script or command when the container is started.
ENTRYPOINT ["/usr/sbin/nginx_setup.sh"]
