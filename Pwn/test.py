import os 
import os

l=['netcat','shell','pwntools_1', 'pwntools_2', 'pwntools_3','integer_overflow', 'overflow1', 'overflow2', 'overflow3','ret2win1', 'ret2win2', 'ret2win3', 'ret2win4','canary0', 'canary1', 'ret2libc1', 'ret2libc2', 'ret2libc3','format1', 'format2', 'format3','challenger',  'grandmaster'    ]

for i in range(len(l)):
	os.system(f"cp Dockerfile ./{l[i]}/Dockerfile")
	docker_compose=f'''version: '3'
services:
  {l[i]}:
    build: .
    ports:
      - {5000+i}:10001
    read_only: true
    cap_drop:
      - all
              
    restart: on-failure

    deploy:
        resources:
            limits:
              cpus: '0.2'
              memory: 1000M'''

	with open(f"{l[i]}/docker-compose.yml","w+") as f:
		f.write(docker_compose)

