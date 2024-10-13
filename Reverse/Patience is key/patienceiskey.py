import time

a = [83,100,97,118,118,108,104,98,124,122,113,57,83,97,62,63,99,116,77,99,117,97,39,114,110,98,103,92,53,86,89,115,56,86,59,100,127,104,81,62,100,78,115,127,120,104]
b = time.localtime()
c = b.tm_hour

print()
print("== PATIENCE IS KEY ==")
print("--   Author: jio   --")
print()

print("I'll give you flag[x]\nx = ", end="")
x = int(input())

if (x < 0):
    print("Are you serious?? (●__●)")
    exit(1)

if (x % 24 == c):
    print("Here you go: '", chr(a[x] ^ c), "'", sep="")
    print("See you LATER")
else:
    if (x < c):
        print("too late! goodbye ~~")
    else:
        print("too early for that, be patient!!")