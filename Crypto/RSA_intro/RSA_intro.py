from Crypto.Util.number import getPrime, inverse, bytes_to_long, long_to_bytes

def generate_keys():
    p = getPrime(128)
    q = getPrime(128)
    n = p * q
    e = 0x10001
    phi = (p - 1) * (q - 1)
    d = inverse(e, phi)

    public_key = {
        'n': n,
        'e': e
    }

    private_key = {
        'n': n,
        'd': d
    }

    return public_key, private_key

def encrypt(message, public_key):
    m = bytes_to_long(message)
    ciphertext = pow(m, public_key['e'], public_key['n'])
    return ciphertext

def decrypt(ciphertext, private_key):
    n = private_key['p'] * private_key['q']
    d = private_key['d']
    m = pow(ciphertext, d, n)
    return long_to_bytes(m)

# Main execution
if __name__ == "__main__":
    public_key, private_key = generate_keys()

    flag = #hidden
    ciphertext = encrypt(flag, public_key)

    print(f"public_key = {public_key}")

    print(f"ciphertext = {ciphertext}")

""" CODE OUTPUT :
public_key = {'n': 41073911554572767455647972366020838561083369570044303703887729964573731410719, 'e': 65537}
ciphertext = 1531724154087084407990783685968290906619155990636959335349158954062363819668
"""