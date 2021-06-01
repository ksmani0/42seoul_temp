FROM alpine:3.12.0

RUN apk update \
	&& apk --update --no-cache add \
	bash vsftpd openssl

#Server IP address
ARG PASV=${pasv_address}

ENV PASV_ENABLE=YES \
    PASV_MIN_PORT=20000 \
    PASV_MAX_PORT=20003 \
	NODE_ADDRESS=${PASV}
#In passive mode, specify an arbitrary range of available ports from 1024 to 65546.

COPY vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY ftps_setup.sh /

#20: FTP port
#21: Port number required by the assignment.
EXPOSE 20 21 20000-20004
ENTRYPOINT ["sh", "ftps_setup.sh"]
