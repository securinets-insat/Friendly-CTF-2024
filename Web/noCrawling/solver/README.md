# noCrawling writeup :

we open the web page and notice there is nothing useful on it so we start looking for hints in the description and name of the task , we google ``special file to avoid crawling web`` and notice after some research that there is a special files that developers use to block webCrawlers and that file is ``robots.txt`` , we navigate to that file with the link : ``http://nocrawling.web.securinets.tn/robots.txt`` and we get this text 
```User-agent: *
Disallow: /fakeRoute

User-agent: *
Allow: /

Securinets{Web_Crawlers_cant_Get_Me}   
```

getting our flag : ``Securinets{Web_Crawlers_cant_Get_Me}``

written by : **Chuuya**