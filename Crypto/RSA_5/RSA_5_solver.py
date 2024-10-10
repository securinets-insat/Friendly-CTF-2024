from Crypto.Util.number import long_to_bytes
from gmpy2 import iroot
#given

n = 4158976535280875356153143029400138606631911282615998945998160077340432430932973423750943391960196483694167910518065556922377672953850295221500202563299183
e = 3
ciphertext = 3135649947550540713552812162689354656188223479101376753019397970115238737767745251583984962792624845669611431128409099660400723554948444847174399076551692

len_flag = 22

""" 
    Use the length of the flag to calculate the 
    number of bits of M^e to narrow down the 
    range of decryption
    """
val = ( (len_flag * 8) - 4 ) * e
print(val)
min = 1 << val
max = 1 << (8 * e * (len_flag))


i = 0
while ciphertext < min:
    ciphertext += n
    i += 1

counter = 0

while ciphertext < max:
    root , ismultiple = iroot(ciphertext,e)
    if ismultiple:
        try:
            print('Securinets{' + long_to_bytes(root).decode('utf-8') + '}')
            print(f"counter: {counter}")
        except UnicodeDecodeError:
            pass
    ciphertext += n
    counter+= 1
print('ended')

