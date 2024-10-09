# Secret Agent writeup

we first navigate to the web page to find some HTML telling us that we are not one of their agents and we need to have special clearence to access their platform 

we are given a useful link in the challange description we navigate to it to find that it's talking about a header in ``HTTP`` called ``USER-AGENT`` 
```
The User-Agent request header is a characteristic string that lets servers and network peers identify the application, operating system, vendor, and/or version of the requesting user agent.
```

we can use ``curl`` , ``postman`` or ``burpsuite`` to change this ``HTTP`` header , i am going to be using ``curl`` as it is available in both ``windows`` and ``linux`` and doesn't require any installation 

we can change the ``USER-AGENT`` header in ``HTTP`` with this `curl` command :
```
curl -X GET http://specialagent.web.securinets.tn/ -H "User-Agent: your_user_agent"
```
but the problem is we don't know the special agents code name, so we go back to the HTML and start reading the source code in hope to find a hint (we can read the source code by right clicking and 'view page source')

and there is is : 
```
<!--This is a very important secret of our own , only our Agent_Z32 have access to it! -->
```
a comment giving us the name of the user agent , so we run our command with the accuired user-agent 
```
curl -X GET http://specialagent.web.securinets.tn/ -H "User-Agent: Agent_Z32"
```

a quick read to the output and we'll find our flag `securinets{h34d3r5-h0ld5-v4lu4bl3-1nf05}`

written by : **Chuuya**