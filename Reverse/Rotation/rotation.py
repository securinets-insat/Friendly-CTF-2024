print("Give me the flag i'll give you points :)")
print("flag: ", end="")

flag = input()
output = ""

for i in range(len(flag)):
    output = output + chr(ord(flag[i]) - i)

if output == "Sdarndh^ljqg$g&e!^\\LU^I<=7+7CHC[YXWZ":
    print("Correct! +999 points")
else:  
    print("Wrong! Try again :)")