FROM alpine:latest
RUN apk update
RUN apk upgrade
RUN apk add socat

RUN adduser -h /home/somebody -s /bin/bash ctf -u 1001 | echo ctf | echo ctf

WORKDIR /home/ctf

COPY ./flag.txt /home/ctf/flag.txt
COPY ./asker /home/ctf/asker
COPY ./question.txt /home/ctf/question.txt

RUN chmod +x ./asker /home/ctf/asker
USER ctf

CMD socat TCP-LISTEN:1338,reuseaddr,fork EXEC:"./asker "