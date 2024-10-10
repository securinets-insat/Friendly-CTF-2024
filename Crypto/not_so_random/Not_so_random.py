from random import getrandbits

flag = 'Securinets{1234}'
assert flag [:11] == 'Securinets{'

import random

def rotate_key(key):
    return ((key >> 1) | ((key & 1) << 63)) & 0xFFFFFFFFFFFFFFFF

def xor_with_key(text_chunk, key):
    chunk_len = len(text_chunk)
    chunk_val = int.from_bytes(text_chunk.ljust(8, b'\x00'), byteorder='big')
    xored_chunk = (chunk_val ^ key).to_bytes(8, byteorder='big')
    return xored_chunk[:chunk_len]

def encrypt(plaintext):
    # Generate a random 8-byte key
    key = getrandbits(64)

    encrypted = b''
    prev_chunk = b''

    for i in range(0, len(plaintext), 8):
        chunk = plaintext[i:i+8].encode()

        if i == 0:
            encrypted_chunk = xor_with_key(chunk, key)

        else:

            key = rotate_key(key)

            encrypted_chunk = xor_with_key(chunk, key)
            encrypted_chunk = bytes(a ^ b for a, b in zip(encrypted_chunk, prev_chunk))

        encrypted += encrypted_chunk
        prev_chunk = encrypted_chunk

    return encrypted


encrypted_message= encrypt(flag)
print(f"Encrypted = {encrypted_message.hex()}")


""" CODE OUTPUT :
Encrypted = baf1c3db32a7f9dc3a48e8c5669fed57215e9fb1989c3ce6433f3bfb0ff78f7fb9961caeb49a007045a8e6f4a7f018b0
"""