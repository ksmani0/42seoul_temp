# mysql server 를 초기 세팅한다.
# alpine 에 새로운 유저를 추가하지 않았기때문에 편의상 rootㄹ 를 사용
# datadir은 왜하는지 모르겠음
mysql_install_db --user=root --datadir=/var/lib/mysql

# set database 
mysqld --user=root --bootstrap < init_mysql.sql

# mysqld --user=root 보단 mysqld_safe 를 통해서 실행하는 것을 권장한다.
mysqld_safe --user=root --datadir=/var/lib/mysql

# set database 
#mysql --user=root < init_mysql.sh
#nohup init_mysql.sh &
#echo "CREATE DATABASE wordpress;" | mysql --user=root
#echo "GRANT ALL PRIVILEGES ON *.* TO 'mykang'@'%' IDENTIFIED BY PASSWORD 'mykang' WITH GRANT OPTION;" | mysql --user=root
#echo "FLUSH PRIVILEGES;" | mysql --user=root
