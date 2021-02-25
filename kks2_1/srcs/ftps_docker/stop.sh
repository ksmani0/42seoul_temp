echo "docker stop"
docker stop $(docker ps -a -q)
echo "docker rm"
docker rm $(docker ps -a -q)
