#setup.sh: docker build -t ft_services-influxdb srcs/influxdb >> logs.txt
FROM alpine:3.12.0

RUN apk update && \
	apk --update --no-cache add influxdb \
	--repository http://dl-2.alpinelinux.org/alpine/edge/community/

RUN mkdir -p /etc/influxdb
RUN mkdir -p /var/lib/influxdb
COPY influxdb.conf /etc/influxdb/influxdb.conf
EXPOSE 8086
#Default port that runs the InfluxDB HTTP service.

COPY ./influxdb_setup.sh  /usr/sbin/influxdb_setup.sh
RUN chmod +x /usr/sbin/influxdb_setup.sh

#Equivalent to doing ENTRYPOINT ["influxd"] after mkdir -p /run/influxd.
ENTRYPOINT ["/usr/sbin/influxdb_setup.sh"]
#DB name, user, password, etc. can be resolved with global variables.
#Can do a Google search with keywords such as influxdb environment variables.
