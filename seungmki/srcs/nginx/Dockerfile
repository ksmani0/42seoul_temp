FROM alpine:3.12.0

#Install nginx and dependencies
#openssh includes openssh-server and openssh-cliet. Only openssh-server is used, so install only this.
RUN apk update && \
	apk --update --no-cache add nginx openssl openssh-server

#In order to run the nginx daemon, there must be a directory in '/run/nginx' path.
#/var/www is used as the root directory.
RUN mkdir -p /run/nginx; mkdir -p /var/www
RUN echo "root:1234" | chpasswd
#root:ftservice
#Create an account without a password. Account login using ssh key is possible

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -subj \
	"/C=KR/ST=Seoul/L=Gaepodong/O=42Seoul/OU=2nd_term_Gam/CN=127.0.0.1" -keyout /etc/ssl/private/nginx.key -out /etc/ssl/certs/nginx.crt
RUN openssl dhparam -dsaparam -out /etc/ssl/certs/dhparam.pem 2048
#dhparam is one of the ways to help encryption during SSL communication.
#Increase the encryption complexity by using the dhparam key.

RUN ssh-keygen -A
#Allow ssh connection
#If system does not already have host keys(rsa1, rsa, dsa, ecdsa and ed25519),
#ssh-keygen -A will create them

COPY sshd_config /etc/ssh/
COPY default.conf /etc/nginx/conf.d/
COPY index.html /var/www/
COPY nginx_setup.sh /
#The root directory is the starting point where index.html of the server is located.
#Based on this, it receives the url, finds the document, and responds to the client.

EXPOSE 80 443 22
#Container port numbers setting. port 22 for ssh
#Actually, Port 22 is already set as the SSH port on the Mac...0_0a

#ENTRYPOINT executes a script or command when the container is started.
ENTRYPOINT ["sh", "nginx_setup"]
