#!/bin/bash -e

BLUE="\033[34m"
CYAN="\033[36m"
YELLOW="\033[93m"
END="\033[0m"

welcome()
{
	echo -e $BLUE
	echo "##################################################################################"
	echo -e $CYAN
	echo " seungmki's                                                                       "
	echo "    FFF               SSSS     EEE    R  RRRR V     V I   CCCCC     EEE     SSSS  "
	echo "   F   F   T         S    S   E   E   R R     V     V    C     C   E   E   S    S "
	echo "   F       T         S       E     E  RR       V   V  I C         E     E  S      "
	echo " FFFFFFF TTTTT        SSSS  EEEEEEEEE R        V   V  I C        EEEEEEEEE  SSSS  "
	echo "   F       T              S  E        R         V V   I C         E             S "
	echo "   F       T         S    S  E      E R         V V   I  C     C  E      E S    S "
	echo "   F        TTT ----  SSSS    EEEEEE  R          V    I   CCCCC    EEEEEE   SSSS  "
	echo -e $BLUE
	echo "##################################################################################"
	echo -e $END
}

#Install minikube if it is not installed.
#metrics-server collects metrics such as CPU and memory usage and displays them on the dashboard.
#export MINIKUBE_HOME=~/goinfre for cluster
#if [[ $(minikube status | grep -c "Running") == 0 ]]
#then
#	minikube start #For my home
	minikube start --driver virtualbox #For cluster
	minikube addons enable metrics-server
	minikube addons enable dashboard
	minikube addons enable metallb
#fi
#minikube addons enable dashboard: Dashboards can be displayed directly in the browser
#without entering a token.
#minikube addons enable metallb: No need to use complex Kubernetes manifest methods.

#This command is used to connect my host's docker and minikube's vm
eval $(minikube docker-env)

#MetalLB
#In non-Linux, must check the path with which sed before using sed.
MINI_IP=$(minikube ip)
sed -i "s/MINI_IP/$MINI_IP/g" srcs/metallb.yaml
sed -i "s/MINI_IP/$MINI_IP/g" srcs/nginx/nginx.yaml
sed -i "s/MINI_IP/$MINI_IP/g" srcs/phpmyadmin/phpmyadmin.yaml
sed -i "s/MINI_IP/$MINI_IP/g" srcs/wordpress/wordpress.yaml
sed -i "s/MINI_IP/$MINI_IP/g" srcs/ftps/ftps.yaml
sed -i "s/MINI_IP/$MINI_IP/g" srcs/grafana/grafana.yaml

sed -i "s/MINI_IP/$MINI_IP/g" srcs/phpmyadmin/config.inc.php
sed -i "s/MINI_IP/$MINI_IP/g" srcs/ftps/vsftpd.conf
sed -i "s/MINI_IP/$MINI_IP/g" srcs/wordpress/wordpress.sql
kubectl apply -f ./srcs/metallb.yaml
printf "${YELLOW}...MetalLB was applied...\n${END}"

#Nginx
#Installation contents are appended to logs.txt without displaying them on the consol
docker build -t nginx srcs/nginx >> logs.txt
kubectl apply -f ./srcs/nginx/nginx.yaml >> logs.txt
printf "${YELLOW}...Nginx image building and deployment done...\n${END}"

#Mysql
docker build -t mysql srcs/mysql >> logs.txt
kubectl apply -f ./srcs/mysql/mysql.yaml >> logs.txt
printf "${YELLOW}...MySQL image building and deployment done...\n${END}"

#phpmyadmin
docker build -t phpmyadmin srcs/phpmyadmin >> logs.txt
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml >> logs.txt
printf "${YELLOW}...phpMyAdmin image building and deployment done...\n${END}"

#Wordpress
docker build -t wordpress srcs/wordpress >> logs.txt
kubectl apply -f ./srcs/wordpress/wordpress.yaml >> logs.txt
printf "${YELLOW}...WordPress image building and deployment done...\n${END}"

#FTPS: Needed to transfer files
docker build -t ftps srcs/ftps >> logs.txt
kubectl apply -f ./srcs/ftps/ftps.yaml >> logs.txt
printf "${YELLOW}...FTPS image building and deployment done...\n${END}"

#Influxdb: Data service specialized for storing and utilizing time series data.
docker build -t influxdb srcs/influxdb >> logs.txt
kubectl apply -f ./srcs/influxdb/influxdb.yaml >> logs.txt
printf "${YELLOW}...InfluxDB image building and deployment done...\n${END}"

#Telegraf: Collecting various data.
docker build -t telegraf srcs/telegraf >> logs.txt
kubectl apply -f ./srcs/telegraf/telegraf.yaml >> logs.txt
printf "${YELLOW}...Telegraf image building and deployment done...\n${END}"

#Grafana: An open source visualization tool that allows to effectively visualize stacked data.
docker build -t grafana srcs/telegraf >> logs.txt
kubectl apply -f ./srcs/grafana/grafana.yaml >> logs.txt
printf "${YELLOW}...Grafana image building and deployment done...\n${END}"

welcome #A table with namespace, name, and url is displayed.
minikube service list

#Show IP address can be accssed.
echo "⭐️ seungmki's ft_services IP(minikube ip): $MINI_IP"

printf "${YELLOW}If you want to see dashboard, enter 'minikube dashboard' in terminal\n${END}"
