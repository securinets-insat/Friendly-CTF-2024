import random




flag = #hidden

random_number = random.randint(1, 100000000)

assert random_number < 100000000
random.seed(random_number)

encrypted_flag = ""


for letter in flag:
    random_factor = random.randint(1,30)
    temp = (ord(letter) + random_factor) % 81
    encrypted_flag += chr(temp + ord("0"))

print(f'encrypted_flag = "{encrypted_flag}"')

""" CODE OUTPUT :
encrypted_flag = "5W_k`LYT`prBfxexVQ]{`[}W?dxZkqu_XyXu]RnM_"
"""