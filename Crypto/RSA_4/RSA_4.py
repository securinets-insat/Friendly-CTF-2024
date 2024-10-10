from Crypto.Util.number import bytes_to_long, long_to_bytes

# Load my friends keys
moduli = []
with open("keys.txt", "r") as f:
    moduli = [int(line.strip()) for line in f.readlines()]

e = 17

flag = #hidden
m = bytes_to_long(flag)

# Encrypt the message with each modulus and save the ciphertexts
ciphertexts = []
with open("ciphertexts.txt", "w") as f:
    for n in moduli:
        c = pow(m, e, n)
        ciphertexts.append(c)
        f.write(f"{c}\n")  # Save the ciphertext into ciphertext.txt
