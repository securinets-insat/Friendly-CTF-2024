from pwn import *


p=remote("localhost" , 10001)

p.sendline("aaa")


p.interactive()