FROM alpine:3.12.0

RUN apk update && \
	apk --update --no-cache add influxdb

RUN mkdir -p /etc/influxdb
COPY influxdb.conf /etc/influxdb/influxdb.conf

EXPOSE 8086
#Default port that runs the InfluxDB HTTP service.

#Equivalent to doing ENTRYPOINT ["influxd"] after mkdir -p /run/influxd.
ENTRYPOINT  ["/usr/sbin/influxd"]
#DB name, user, password, etc. can be resolved with global variables.
#Can do a Google search with keywords such as influxdb environment variables.
