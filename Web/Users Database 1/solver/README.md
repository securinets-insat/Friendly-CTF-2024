# Users database writeup

when we first navigate the webpage we notice an input box with a search button , we try interracting with the pag a little so we notice that the page is interracting with a database , and when we say database we say `SQL` 
> Structured Query Language is a domain-specific language used to manage data, especially in a relational database management system. It is particularly useful in handling structured data, i.e., data incorporating relations among entities and variables.

and as a pentester when we say `SQL` we directli think of `SQL injections` (we are going to talk more about them in the workshops)\
so the good hacker i am , i run to `payloads of all thing` searching for **sql injection** getting the very common **sqli** payload : `' or 1=1 -- -` , we go ahead and try it and there we go we can access all the users in the database , we scroll a bit to ind our flag is the password of the user `victor_frankenstein`

flag: `Securinets{1nject0r_4tTack_1s_FuN!}`

written by: **Chuuya**