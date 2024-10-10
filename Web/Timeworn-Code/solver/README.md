# Timeworn Code Writeup

when we first visit the webpage we notice there is nothing on the screen except for the **Hello Hackers** and the hint in the bottom right saying **made with nginx + php-fpm configurations.** , so the good hackers we are we run to google asking for `nginx and php-fpm vulnerabilities` and evidently the first result we get tells us that there is a registered vulnerability `CVE-2019-11043` 
> CVE stands for Common Vulnerabilities and Exposures. CVE is a glossary that classifies vulnerabilities. The glossary analyzes vulnerabilities and then uses the Common Vulnerability Scoring System (CVSS) to evaluate the threat level of a vulnerability.

after getting our vulnerability we start searching for a **POC** (proof of concept) or an **exploit** 

after some searching i stumbled on this [github]() repo , i downloaded the exploit.py file and ran it using 
```
python3 exploit.py --target http://timeworn_code.web.securinets.tn/index.php
```
and after waiting a while i got 
```
✅ Success: Remote Code Execution exploit successfully deployed!
```
and there we go, now we have an RCE that we can exploit to get our flag \
to do this we just visit 
```
http://timeworn_code.web.securinets.tn/index.php?a=ls
```
to list all the files , among the files listed we notice `flag655616` , so we go ahead and replace `ls` with `cat flag655616` and there you have it \
your flag is : `Securinets{Forgotten_Vulnerabilities_Unleashed}`

written by : **Chuuya**