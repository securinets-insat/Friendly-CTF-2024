import random

encrypted_flag = "5W_k`LYT`prBfxexVQ]{`[}W?dxZkqu_XyXu]RnM_"
decrypted = False
flag_prefix = 'Securinets{'
viable_seeds = []
counter = 0

while not decrypted and counter < 100000001:
    if counter % 100000 == 0:
        print(counter)
    possible_seed = True
    random.seed(counter)
    for i in range(len(flag_prefix)):
        letter = encrypted_flag[i]
        decrypted_letter = flag_prefix[i]
        temp = ord(letter) - ord("0")
        random_factor = random.randint(1, 30)
        temp = temp - random_factor
        if  temp != ord(decrypted_letter) and (temp + 81) != ord(decrypted_letter) :
            possible_seed = False
        if not possible_seed:
            break
    if possible_seed:
        print("this may be a viable seed :" + str(counter))
        viable_seeds.append(counter)
    counter += 1


print(viable_seeds)

for seed in viable_seeds:
    random.seed(seed)
    decrypted_flag = ""
    sup = []
    for i in range(len(encrypted_flag)):
        letter = encrypted_flag[i]
        temp = ord(letter) - ord("0")
        random_factor = random.randint(1, 30)
        temp = temp - random_factor
        if temp < 127:
            sup.append(chr(temp + 81))
    for i in range(len(sup)):
        letter = sup[i]
        ascii = ord(letter)
        if ascii > 127:
            sup [i] = chr(ascii - 81)
    print("Possible final flag is " + ''.join(sup))
    print('-------- next seed ---------')


#random_number = 62120282




