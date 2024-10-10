import binascii


def rotate_key(key):
    return ((key >> 1) | ((key & 1) << 63)) & 0xFFFFFFFFFFFFFFFF


def xor_with_key(text_chunk, key):
    chunk_len = len(text_chunk)
    chunk_val = int.from_bytes(text_chunk.ljust(8, b'\x00'), byteorder='big')
    xored_chunk = (chunk_val ^ key).to_bytes(8, byteorder='big')
    return xored_chunk[:chunk_len]


def recover_key(ciphertext, known_plaintext):
    first_cipher_chunk = ciphertext[:8]
    first_plaintext_chunk = known_plaintext[:8].encode()

    key = int.from_bytes(first_cipher_chunk, byteorder='big') ^ int.from_bytes(first_plaintext_chunk, byteorder='big')
    return key

def decrypt(ciphertext, key):
    decrypted = b''
    prev_chunk = b''

    for i in range(0, len(ciphertext), 8):
        chunk = ciphertext[i:i+8]

        if i == 0:
            decrypted_chunk = xor_with_key(chunk, key)
        else:
            key = rotate_key(key)
            decrypted_chunk = bytes(a ^ b for a, b in zip(chunk, prev_chunk))
            decrypted_chunk = xor_with_key(decrypted_chunk, key)

        decrypted += decrypted_chunk
        prev_chunk = chunk

    return decrypted.decode(errors='ignore').strip()



encrypted_flag = binascii.unhexlify('baf1c3db32a7f9dc3a48e8c5669fed57215e9fb1989c3ce6433f3bfb0ff78f7fb9961caeb49a007045a8e6f4a7f018b0')
flag_prefix = "Securinets{"

# Recover the key using the known plaintext prefix
key = recover_key(encrypted_flag, flag_prefix)
print(f"Recovered Key: {key}")

# Decrypt the message using the recovered key
decrypted_message = decrypt(encrypted_flag, key)
print(f"Decrypted: {decrypted_message}")


#flag : Securinets{It__Was__n0t__S0__rand0m__aft3r__all}
