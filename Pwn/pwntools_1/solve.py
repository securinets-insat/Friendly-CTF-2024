from pwn import *


p=remote("localhost" , 5002)

p.sendline("aaa")


p.interactive()