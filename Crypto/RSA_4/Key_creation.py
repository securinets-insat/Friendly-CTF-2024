from Crypto.Util.number import getPrime

# Number of moduli (we'll use 10000 for the task)
num_moduli = 10000

# Step 1: Generate num_moduli sets of primes and compute n_i = p_i * q_i
moduli = []
e = 17

# Generate and store the moduli
with open("keys.txt", "w") as f:
    for i in range(num_moduli):
        p = getPrime(512)
        q = getPrime(512)
        n = p * q
        moduli.append(n)
        f.write(f"{n}\n")  # Save n to keys.txt
