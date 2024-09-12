from pwn import *



p=remote("localhost" , 10001)
#p=process("./main")

for i in range(0x10):
	value=p.recvline()
	value=int(value[:-1],10)
	#print(value)
	p.sendline(str(value))


p.interactive()