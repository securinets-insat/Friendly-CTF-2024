#given
public_key = {'n': 41073911554572767455647972366020838561083369570044303703887729964573731410719, 'e': 65537}
ciphertext = 1531724154087084407990783685968290906619155990636959335349158954062363819668

from Crypto.Util.number import long_to_bytes, inverse

"""factor n using any available tool or a personnal script
I recommend https://www.alpertron.com.ar/ECM.HTM"""

p = int(' 170 887544 648074 842902 147703 596872 069069'.replace(" ", ""))
print(p)
q = public_key ['n'] // p
print(q)
phi = (p-1) * (q-1)

private_key = {
    'n' : public_key['n'],
    'd' : inverse(public_key['e'] , phi),
}

# reuse the decode function given

def decrypt(ciphertext, private_key):
    n = private_key['n']
    d = private_key['d']
    m = pow(ciphertext, d, n)
    return long_to_bytes(m)

print(decrypt(ciphertext, private_key).decode('utf-8'))