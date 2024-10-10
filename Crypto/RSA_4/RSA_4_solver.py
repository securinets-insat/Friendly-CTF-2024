from Crypto.Util.number import long_to_bytes

'''
Classic CRT vulnerability
'''

# Custom function to implement the Chinese Remainder Theorem
def custom_crt(moduli, remainders):
    M = 1  # Product of all moduli
    #for i in range(len(moduli)):
    for i in range(7):
        M *= moduli[i]

    result = 0
    #for i in range(len(moduli)):
    for i in range(7):#this work better and faster no need to thru every address
        Mi = M // moduli[i]  # M_i = M / n_i
        inv = pow(Mi, -1, moduli[i])  # Modular inverse of M_i mod n_i
        result += remainders[i] * Mi * inv  # Sum up the result according to CRT formula

    return result % M  # Final result modulo M

# Function to find the e-th root of a number using binary search
def int_nth_root(x, n):
    low, high = 0, x
    while low < high:
        mid = (low + high) // 2
        if mid ** n < x:
            low = mid + 1
        else:
            high = mid
    return low

# Step 1: Load the moduli and ciphertexts
moduli = []
ciphertexts = []

with open("keys.txt", "r") as f:
    moduli = [int(line.strip()) for line in f.readlines()]

with open("ciphertexts.txt", "r") as f:
    ciphertexts = [int(line.strip()) for line in f.readlines()]

e = 17

# Step 2: Use the custom CRT function to combine the ciphertexts
combined_ciphertext = custom_crt(moduli, ciphertexts)

# Step 3: Find the integer e-th root of the combined ciphertext
m = int_nth_root(combined_ciphertext, e)

# Step 4: Output the decrypted message
print("Decrypted message (m):", m)
print("Decrypted message (as bytes):", long_to_bytes(m))
