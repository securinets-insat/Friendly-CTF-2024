# How to run the web challanges on your local machine

first we need to clone the git directory containing all the **Friendly CTF** challanges 
```
git clone https://github.com/securinets-insat/Friendly-CTF-2024.git
```
then we change directory into the Web subdirectory
```
cd Friendly-CTF-2024/Web/
```
then we need to [install](https://medium.com/@tomer.klein/step-by-step-tutorial-installing-docker-and-docker-compose-on-ubuntu-a98a1b7aaed0) docker and docker-compose 

after the installation we can go ahead and run any web challange we want , to run the challanges we need first to identify which port its going to run on\
we are going to take `DevTools_for_the_win` as an example :

first we need to change directory to the challange we want to run , in our case `DevTools_for_the_win`
```
cd DevTools_for_the_win
```
then we need to identify which port it is going to run on 
```
cat compose.yaml
```
getting an output
```
services:
  web:
    build: .
    ports:
      - "5011:80"
```
we are not going to go too much into details how docker-compose works , the only thing we are interrested in is 
```
ports:
    - "5011:80"
```
which means it is mapping the docker port `80` to our local machine port `5011` so to access the challange after running it we just need to go to `http://localhost:machine_port` in our case `http://localhost:5011`

so to run the up once we are inside the folder where the `compose.yaml` is , we just need to run 
```
sudo docker-compose up --build -d
```

and there you go you go the app running 

btw you can change the machine port in your compose.yaml you just need to make sure it is not reserved 

ps: to kill a container after being done with it you just need to find it's `ace9b7df9d65` with 
```
sudo docker ps
```
then 
```
sudo docker kill [container_id]
```

written by: **Chuuya**
