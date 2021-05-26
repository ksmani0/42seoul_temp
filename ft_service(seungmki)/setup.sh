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
}

#Install minikube if it is not installed.
#metrics-server collects metrics such as CPU and memory usage and displays them on the dashboard.
if [[ $(minikube status | grep -c "Running") == 0 ]]
then
	minikube start --driver=hyperkit #For my home
#	minikube start --driver virtualbox #For cluster
	minikube addons enable metrics-server
	minikube addons enable dashboard
	minikube addons enable metallb
fi

#This command is used to connect my host's docker and minikube's vm
eval $(minikube docker-env)

#MetalLB
kubectl apply -f ./srcs/metallb.yaml
printf "${YELLOW}...MetalLB was applied...\n${END}"

#Nginx
#Installation contents are appended to logs.txt without displaying them on the consol
docker build -t ft_services-nginx srcs/nginx >> logs.txt
printf "${YELLOW}...Nginx image building completed...\n${END}"
kubectl apply -f ./srcs/nginx/nginx.yaml >> logs.txt
printf "${YELLOW}...Nginx deployment completed...\n${END}"

#Mysql
docker build -t ft_services-mysql srcs/mysql >> logs.txt
printf "${YELLOW}...MySQL image building completed...\n${END}"
kubectl apply -f ./srcs/mysql/mysql.yaml >> logs.txt
printf "${YELLOW}...MySQL deployment completed...\n${END}"

#phpmyadmin
docker build -t ft_services-phpmyadmin srcs/phpmyadmin >> logs.txt
printf "${YELLOW}...phpMyAdmin image building completed...\n${END}"
kubectl apply -f ./srcs/phpmyadmin/phpmyadmin.yaml >> logs.txt
printf "${YELLOW}...phpMyAdmin deployment completed...\n${END}"

#Wordpress
docker build -t ft_services-wordpress srcs/wordpress >> logs.txt
printf "${YELLOW}...WordPress image building completed...\n${END}"
kubectl apply -f ./srcs/wordpress/wordpress.yaml >> logs.txt
printf "${YELLOW}...WordPress deployment completed...\n${END}"

#FTPS: Needed to transfer files
docker build -t ft_services-ftps srcs/ftps >> logs.txt
printf "${YELLOW}...FTPS image building completed...\n${END}"
kubectl apply -f ./srcs/ftps/ftps.yaml >> logs.txt
printf "${YELLOW}...FTPS deployment completed...\n${END}"

#Influxdb: Data service specialized for storing and utilizing time series data.
docker build -t ft_services-influxdb srcs/influxdb >> logs.txt
printf "${YELLOW}...InfluxDB image building completed...\n${END}"
kubectl apply -f ./srcs/influxdb/influxdb.yaml >> logs.txt
printf "${YELLOW}...InfluxDB deployment completed...\n${END}"

#Telegraf: Collecting various data.
docker build -t ft_services-telegraf srcs/telegraf >> logs.txt
printf "${YELLOW}...Telegraf image building completed...\n${END}"
kubectl apply -f ./srcs/telegraf/telegraf.yaml >> logs.txt
printf "${YELLOW}...Telegraf deployment completed...\n${END}"

#Grafana: An open source visualization tool that allows to effectively visualize stacked data.
docker build -t ft_services-grafana srcs/telegraf >> logs.txt
printf "${YELLOW}...Grafana image building completed...\n${END}"
kubectl apply -f ./srcs/grafana/grafana.yaml >> logs.txt
printf "${YELLOW}...Grafana deploymwnt completed...\n${END}"

#Show IP address can be accssed.
echo "⭐️seungmki's ft_services IP: 192.168.99.100"

welcome
