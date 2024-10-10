# Users database 2 writeup

when we first navigate the webpage we notice like the version 1 of this challange `Users database` an input box with a search button , we try interracting with the page a little and we notice the same behaviour as before 

so we try the same payload as before : `' or 1=1 -- -` , but this time we notice under the input box `Searching for username :' 1=1 -` we look at the username and notice it is not the same one we provided , weird , where did the `OR` and `--` go ?

well it seems the backend is running some kind of filtration script with blacklisted words , but that never stoped us before 

we start messing with the input field a little to notice that the `#` is not filtered and the `#` is used for commenting in `sql` same as `--` , so now we can craft a different version of our vulnerability where we don't use `OR` or `--`

the payload i came up with is `' UNION SELECT * from users #`

we execute this payload and there we go , we get all the users again , but now when we scroll around we can't find our flag , but wait what is this weird password of `emily_hernandez` , it ends with `==` and we all know that anything that ends with `==` is base64 encoded \
so we go ahead and use an online base64 decoder to decode `U2VjdXJpbmV0c3tTM1FMX0luajNjdGlvbl9NNHN0M3IhfQ==` to get our flag: `Securinets{S3QL_Inj3ction_M4st3r!}`

written by: **Chuuya**   