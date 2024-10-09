# Methodical mayhem writeup

As the title o the challange hints , its about http methods (``GET``,``POST``,``DELETE``, ... ), so to solve this challange we need to send an http request with the correct method .\
a quick web search or using the provided link in the challange will provide us with a list of http methods , we can try them one by one using postman or curl or any other tool you see fit , and inspect the result .\
in this writeup i'm going to use ``curl`` as it is available in both linux and windows \
we can use this command to send a GET request using ``curl`` \
```
curl -X GET http://methodicalmayhem.web.securinets.tn/
```
ande then we inspect the output , it is simple html , you can read through it and notice there is no flag \
after trying a few methods , it appears that the **PUT** method returns an html with the flag in it 
```curl -X PUT http://methodicalmayhem.web.securinets.tn/```

finalyy we get that the flag is : ``Securinets{PUT_YOUR_HANDS_UP}``


written by : **Chuuya**
