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

# create influxDB cotainer image
docker build -t ft_influxdb ./srcs/influxDB_docker

# create telegraf container image
docker build -t ft_telegraf ./srcs/telegraf_docker

# create grafana container image
docker build -t ft_grafana ./srcs/grafana_docker

# influxDB
kubectl apply -f ./srcs/influxDB_docker/influxdb.yaml
# telegraf
kubectl apply -f ./srcs/telegraf_docker/telegraf.yaml
# grafana
kubectl apply -f ./srcs/grafana_docker/grafana.yaml
