# start kubernetes
minikube start --vm-driver virtualbox

# add plugin
minikube addons metallb
minikube addons metrics-server
minikube addons dashboard  # 왜 하는지 모르겠음...

# start dashboard
minikube dashboard &

# set to docker env of kubernetes
eval $(minikube docker-env)

# install metalLB
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/namespace.yaml
kubectl apply -f https://raw.githubusercontent.com/metallb/metallb/v0.9.5/manifests/metallb.yaml
# On first install only
kubectl create secret generic -n metallb-system memberlist --from-literal=secretkey="$(openssl rand -base64 128)"

# apply configMap
kubectl apply -f ./srcs/metallb/metallb-config.yaml

# create nginx container image
docker build -t ft_nginx ./srcs/nginx_docker

# create phpmyadmin container image
docker build -t ft_phpmyadmin ./srcs/phpmyadmin_docker

# create mysql container image
docker build -t ft_mysql ./srcs/mariaDB_docker

# create mysql container image
docker build -t ft_wordpress ./srcs/wordpress_docker

# create ftps container image
docker build -t ft_ftps ./srcs/ftps_docker

# create influxDB cotainer image
docker build -t ft_influxdb ./srcs/influxDB_docker

# create telegraf container image
docker build -t ft_telegraf ./srcs/telegraf_docker

# create grafana container image
docker build -t ft_grafana ./srcs/grafana_docker


# create deployment and service
# mysql
kubectl apply -f ./srcs/mariaDB_docker/mysql-volume.yaml
kubectl apply -f ./srcs/mariaDB_docker/mysql-deployment.yaml
kubectl apply -f ./srcs/mariaDB_docker/mysql-service.yaml
# phpmyadmin
kubectl apply -f ./srcs/phpmyadmin_docker/phpmyadmin.yaml
# wordrpess
kubectl apply -f ./srcs/wordpress_docker/wordpress.yaml
# nginx
kubectl apply -f ./srcs/nginx_docker/nginx-deployment.yaml
kubectl apply -f ./srcs/nginx_docker/nginx-service.yaml
# ftps
kubectl apply -f ./srcs/ftps_docker/ftps.yaml
# influxDB
kubectl apply -f ./srcs/influxDB_docker/influxdb.yaml
# telegraf
kubectl apply -f ./srcs/telegraf_docker/telegraf.yaml
# grafana
kubectl apply -f ./srcs/grafana_docker/grafana.yaml
