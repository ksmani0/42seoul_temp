#!/bin/sh

#mysql Dockerfile: ENTRYPOINT ["/usr/sbin/mysql_setup.sh"]

#mysqld = Mysql + d(daemon) means a process running in the background, a MySQL server.
mkdir -p /run/mysqld
#Directory for activating mysqld

#mysql_install_db: initializes the MariaDB data directory and,
#if the system tables do not exist, creates them in the mysql database.
mysql_install_db --user=root
#--user=root: The login user used to run mysqld is root.
#The files and directories created by mysqld are owned by this user. 

echo "CREATE DATABASE IF NOT EXISTS wordpress;
FLUSH PRIVILEGES;
GRANT ALL PRIVILEGES ON *.* TO 'seungmki'@'%' IDENTIFIED BY 'seungmki' WITH GRANT OPTION;
FLUSH PRIVILEGES;" | mysqld -u root --bootstrap
#Create wordpress database.
#FLUSH PRIVILEGES: Reload the grant table to immediately reflect the changes.

mysqld -u root
#Server start
