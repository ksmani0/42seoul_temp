#!/bin/bash

mkdir -p /var/ftp

#Create user's home directory (the file will be saved here)
mkdir -p /var/ftp/user

#ssl configuration
mkdir -p /etc/ssl/private
mkdir -p /etc/ssl/certs
openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
-subj "/C=KR/ST=Seoul/L=Gaepodong/O=42Seoul/OU=2nd_term_Gam/CN=localhost" \
-keyout /etc/ssl/private/vsftpd.key -out /etc/ssl/certs/vsftpd.crt

adduser -D $FTP_USER -h /var/ftp/user
chown $FTP_USER:$FTP_USER /var/ftp/user
echo "$FTP_USER:$FTP_PASS" | /usr/sbin/chpasswd

#Start vsFTPd while passing the configuration file as an argument.
vsftpd /etc/vsftpd/vsftpd.conf
