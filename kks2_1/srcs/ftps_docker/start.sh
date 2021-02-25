echo "docker build"
docker build . -t test
echo "docker run"
docker run -it -p 20:20 -p 21:21 -p 20000:20000 -p 20001:20001 test
