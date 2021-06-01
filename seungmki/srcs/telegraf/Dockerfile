FROM alpine:3.12

RUN wget https://dl.influxdata.com/telegraf/releases/telegraf-1.17.3_static_linux_amd64.tar.gz
RUN tar -C . -xzf telegraf-1.15.3_static_linux_amd64.tar.gz
RUN cp -r telegraf-1.17.3/* /
RUN ln -s /bin/sh bash

COPY /telegraf.conf /etc
COPY /telegraf_setup.sh /

ENTRYPOINT ["sh", "telegraf_setup.sh"]
