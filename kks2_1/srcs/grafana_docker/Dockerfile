FROM	alpine:3.12

RUN		apk update && apk upgrade

RUN apk add grafana --repository http://dl-cdn.alpinelinux.org/alpine/edge/community/

COPY	dashboard.yaml	/usr/share/grafana/conf/provisioning/dashboards/
COPY	datasource.yaml	/usr/share/grafana/conf/provisioning/datasources/
COPY	dashboard_custom.json	/usr/share/grafana/public/dashboards/

EXPOSE	3000

ENTRYPOINT ["grafana-server", "--config=/etc/grafana.ini", "--homepath=/usr/share/grafana"]
