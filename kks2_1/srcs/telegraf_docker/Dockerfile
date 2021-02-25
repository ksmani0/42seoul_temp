FROM	alpine:3.12

RUN		apk update && apk upgrade
#RUN		apk add telegraf
RUN		wget https://dl.influxdata.com/telegraf/releases/telegraf-1.13.3-static_linux_amd64.tar.gz
RUN		tar -C . -xzf telegraf-1.13.3-static_linux_amd64.tar.gz
# set path
RUN		cp -r telegraf /etc
RUN		cp -r telegraf/telegraf /usr/sbin
COPY	telegraf.conf /etc/telegraf

# run
ENTRYPOINT	["/usr/sbin/telegraf"]
#ENTRYPOINT ["telegraf", "--config=/etc/telegraf.conf"]
