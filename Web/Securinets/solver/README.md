# Securinets writeup

we enter the website and notice that there are nothing special about , just some HTML , no forms no input nothing , we try accessing ``robots.txt`` hoping to find something useful, but there is no robots.txt\
so we have no choice but to look for subdirectories or routes ourselves, for that we are going to use a very well known tool in the web exploitation comunity and that is ``dirbuster`` ,  there is another CLI which is ``dirb`` but i rather use the graphical interface one \
 we put in our target the link of our web page ``http://securinets.web.securinets.tn/`` and in the wordlist i used the already downloaded in kali linux wordlist ``/usr/share/wordlists/dirbuster/directory-list-2.3-medium.txt`` , you can use another wordlist you just need to go to google and type dirbuster worlist and you'll get alot of wordlists you can use \

 after running dirbuster for a while we notice a pattern emerging , first it found ``/S/`` then it found ``/S/e/`` and then ``/S/e/c/`` 

 you can let the script run until it finds all the subdirectories but with the hints provided in the challange description 
 ```
 Sometimes you just need to look inside of S e c u r i n e t s
 ```
 we can conclude that the flag is in ``/S/e/c/u/r/i/n/e/t/s/`` , we can verify that by navigating to ``http://securinets.web.securinets.tn/S/e/c/u/r/i/n/e/t/s/`` 

 and ther you go our flag is : ``Securinets{Uncover_the_Hidden_Directories}``

 written by : **Chuuya**