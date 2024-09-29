# Description

My friend detected some unusual network activity and suspected a data leak. 📉 Your task is to investigate the provided PCAPNG file to identify the malicious IP address and retrieve the leaked data.

# solver 
craft a python script solver.py to extract data form icmp packet
and then 

```
╰─➤  fcrackzip -u -D -v -p /usr/share/wordlists/rockyou.txt output_file.zip
found file 'flag.txt', (size cp/uc     52/    40, flags 1, chk 58e5)
found file 'icmp.py', (size cp/uc    396/   752, flags 1, chk d5cd)
found file 'sniff.jpg', (size cp/uc  33802/ 33987, flags 1, chk e44e)


PASSWORD FOUND!!!!: pw == qazwsxedc
```

use that pw to get the flag
