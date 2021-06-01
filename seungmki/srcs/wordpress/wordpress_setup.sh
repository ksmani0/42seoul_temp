#!/bin/sh

#mysql -hserver -uid -ppassword < Sql file to run
mysql -hmysql -Dwordpress -uuser -ppass < /wordpress.sql
