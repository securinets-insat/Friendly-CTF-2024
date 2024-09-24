import random

def get_random_consecutive_chars(input_string):
    index = random.randint(0, len(input_string) - 2)
    consecutive_chars = input_string[index:index + 3]
    return consecutive_chars

flag = "Securinets{pyARMOR_1s_n0t_ez_2_CrAcK_4T_4LL!!}"


print("I can only give you 3 letters at a time ¯\\_(ツ)_/¯")
if random.randint(0, 1):
    print("Here you go: ", end="")
else:
    print("Voila ~~ ", end="")
print(get_random_consecutive_chars(flag))
if random.randint(0, 1):
    print("Good luck finding the rest of the flag! (ง •_•)ง")

