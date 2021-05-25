#setup.sh: docker build -t ft_services-grafana srcs/telegraf >> logs.txt
FROM alpine:3.12.0

RUN apk update &&\
	apk --update --no-cache add grafana \
	--repository https://dl-cdn.alpinelinux.org/alpine/latest-stable/community/

#Port number required by assignment.
EXPOSE 3000

COPY dashboards/ /usr/share/grafana/public/dashboards/

ENTRYPOINT ["/usr/sbin/grafana-server", "--homepath=/usr/share/grafana"]
