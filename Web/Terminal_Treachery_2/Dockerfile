FROM python:3.8-slim-buster

RUN apt-get update && \
    apt-get install -y iputils-ping && \
    rm -rf /var/lib/apt/lists/*

WORKDIR /app
COPY requirements.txt requirements.txt
RUN pip3 install -r requirements.txt
RUN groupadd -r peasant -g 433 && \
    useradd -u 431 -r -g peasant -s /sbin/nologin -c "a common peasant" peasant


COPY ./src .
RUN chmod 755 /app

USER peasant

EXPOSE 5000

CMD [ "python3", "-m" , "flask", "run", "--host=0.0.0.0"]


 