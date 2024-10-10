from Crypto.Util.number import long_to_bytes, inverse
from gmpy2 import iroot

# Given values
n = 8298232832557779165642568688802433012489581247231191888479510911015306473265728786076358309051720683403847251927146410008022750148812822375234802808658397
e1 = 5
ciphertext1 = 7611556122577415112210529426872991308187196876396054246914338018377600487553046800777125501339576995163885571672393185787648756786539304271560901275280928
e2 = 17
ciphertext2 = 4426515305111583405180029048732181557535316286857631111340077481869273384649493412824424568570078126498459735464049970809300130889395721864827529236783207



# Step 1: Use the Extended Euclidean Algorithm to find coefficients s1 and s2
def extended_euclidean_algorithm(a, b):
    if a == 0:
        return b, 0, 1
    gcd_val, x1, y1 = extended_euclidean_algorithm(b % a, a)
    x = y1 - (b // a) * x1
    y = x1
    return gcd_val, x, y

def negative_pow(a, b, n):
    res = int(inverse(a, n))
    res = pow(res, b*(-1), n)
    return res

gcd_val, s1, s2 = extended_euclidean_algorithm(e1, e2)

if s1 < 0:
    c1 = negative_pow(ciphertext1, s1, n)
else:
    c1 = pow(ciphertext1, s1, n)
if s2 < 0:
    c2 = negative_pow(ciphertext2, s2, n)
else:
    c2 = pow(ciphertext2, s2, n)
ct = c1*c2 % n
m = int(iroot(ct, gcd_val)[0])
print(long_to_bytes(m).decode('utf-8'))


