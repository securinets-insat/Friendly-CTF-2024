# Devtools for the win writeup :

this is a very simple challange just t get you comfortable using the browse developer tools\
Inspect the web page either by right clicking and choosing inspect or by simply clicking ``F12`` \
 navigate to the ``Debugger`` or ``Application`` tab , then look into the code source  (``html`` -> ``javascript`` -> ``css`` ) comments in the source will lead you from one page to the other , finally the css file will hint about web crawling 

a quick google search will tell you that web crawling is linked with the ``robots.txt`` route , so we navigate to that route and we find :

```
Disallow: /flag875274.txt

User-agent: *
Allow: /
```
we find this disallowed route , we navigate to it with the link ``http://devtools_for_the_win.web.securinets.tn/flag875274.txt`` \
to find the flag ``Securinets{F12CodeBreak3r}``

written by : **Chuuya**
