FROM	alpine:3.12

# install vsftpd
# vsftpd does have support for FTPS
RUN		apk update
RUN		apk add vsftpd
RUN		apk add vim
RUN		apk add openrc
RUN		apk add openssl

# add user for ssl
RUN		mkdir -p /ftp
RUN		adduser -D -h /ftp 'mykang'
RUN		echo 'mykang:mykang' | chpasswd
RUN		echo 'mykang' >> /etc/vsftpd/vsftpd.userlist

# copy vsftp configuration file
COPY	vsftpd.conf	/etc/vsftpd

# create certificate and public key
RUN openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=Lee/CN=localhost" -keyout etc/ssl/private/vsftpd.key -out etc/ssl/certs/vsftpd.crt

# open port 21 for control, open port 20 for transfer
EXPOSE	21 20 20001-20001

# run
COPY	run.sh	/
ENTRYPOINT ["sh", "run.sh"]
