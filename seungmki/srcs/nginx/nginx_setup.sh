#!/bin/sh

#Start ssh daemon and nginx
#daemon off; directive tells Nginx to stay in the foreground.
#Used when there is only one service per container.
/usr/sbin/sshd & /usr/sbin/nginx -g 'daemon off;'
#/usr/sbin/nginx to keep the container running even after the script is finished
