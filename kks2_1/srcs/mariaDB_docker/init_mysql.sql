FLUSH PRIVILEGES;
CREATE DATABASE wordpress;
# 특정 DB 에 계정추가
# create user '<ID>'@localhost identified by '<password>'
# create user 'admin'@localhost identified by '1q2w3e4r'
# select hostm userm password from user;
# 외부에서도 접속가능하도록 허용하는 경우, localhost 를 '%' 로 변경
# create user 'admin'@'%' identified by '1q2w3e4r'
#create user 'admin'@'%' identified by '1q2w3e4r';
create user 'mykang'@'%' identified by 'mykang';

# 특정 스키마의 테이블에만 접근할 수 잇는 계정만들기
# GRANT ALL PRIVILEGES ON '<schem name>'.'<table name>' to '<ID>'@'<HOST>' identified by '<password>' with grant option;
# 만약 select 권한만 주고 싶다면
# GRANT select PRIVILEGES ON '<schem name>'.'<table name>' to '<ID>'@'<HOST>' identified by '<password>' with grant option;
# FLUSH PRIVILEGES; 를 입력하여 권한을 적용합니다.
# show grants for '<ID>'@'<HOST>'
#GRANT ALL PRIVILEGES ON *.* TO 'mykang'@'%' IDENTIFIED BY 'mykang' WITH GRANT OPTION;
GRANT ALL ON *.* TO 'mykang'@'%' WITH GRANT OPTION;
FLUSH PRIVILEGES;
