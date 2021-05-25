#!/bin/bash
#nginx Dockerfile: ENTRYPOINT ["/usr/sbin/nginx_setup.sh"]

#Generate ssl private key and certificate
mkdir -p /etc/nginx/ssl
openssl req -new -x509 -nodes -newkey rsa:4096 \
-keyout localhost-nginx.key -out localhost-nginx.crt -days 365 -subj \
"/C=KR/ST=Seoul/L=Gaepodong/O=42Seoul/OU=2nd_term_Gam/CN=localhost"

mv localhost-nginx.key /etc/nginx/ssl
mv localhost-nginx.crt /etc/nginx/ssl

#Allow ssh connection
#If system does not already have host keys(rsa1, rsa, dsa, ecdsa and ed25519),
#ssh-keygen -A will create them
ssh-keygen -A

#Create an account without a password. Account login using ssh key is possible
adduser --disabled-password ${SSH_USERNAME}
echo "${SSH_USERNAME}:${SSH_PASSWORD}" | chpasswd
#SSH_USERNAME and SSH_PASSWORD created using sercret are designated

#In order to run the nginx daemon, there must be a directory in this path
mkdir -p /run/nginx

#Start ssh daemon
/usr/sbin/sshd

#Start nginx
#daemon off; directive tells Nginx to stay in the foreground
/usr/sbin/nginx -g "daemon off;"
#/usr/sbin/nginx to keep the container running even after the script is finished
