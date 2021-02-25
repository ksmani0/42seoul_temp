FROM	alpine:3.12

# install influxDB
RUN		apk update && apk upgrade
RUN		apk add influxdb

EXPOSE	8086

# run influxDB
#ENTRYPOINT	["sh", "influxd"]
ENTRYPOINT ["/usr/sbin/influxd"]
