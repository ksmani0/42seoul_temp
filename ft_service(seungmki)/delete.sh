kubectl delete svc --all
kubectl delete rc --all #replication controller
kubectl delete pod --all
#minikube delete
docker stop $(docker ps -a -q)
docker rm $(docker ps -a -q)
docker rmi $(docker images -q)
