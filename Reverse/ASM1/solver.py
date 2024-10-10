import sys

# python traduction of the assembly code provided in the challenge
def encrypt(x):
    # Byte swap
    x = ((x & 0x000000FF) << 24) | \
        ((x & 0x0000FF00) << 8)  | \
        ((x & 0x00FF0000) >> 8)  | \
        ((x & 0xFF000000) >> 24)

    # Swap the upper and lower 4 bits (nibbles) in each byte
    x = ((x & 0x0F0F0F0F) << 4) | ((x & 0xF0F0F0F0) >> 4)

    # Swap every pair of bits in the 32-bit integer
    x = ((x & 0x33333333) << 2) | ((x & 0xCCCCCCCC) >> 2)

    # Swap every single bit in the 32-bit integer
    x = ((x & 0x55555555) << 1) | ((x & 0xAAAAAAAA) >> 1)

    # Additional transformation to prevent double encryption from reverting
    x = (x + 0x5A5A5A5A) & 0xFFFFFFFF  # Ensure it stays within 32 bits

    return x

# reversing the code to decrypt the encrypted value
def decrypt(y):
    # Reverse the additional transformation
    y = (y - 0x5A5A5A5A) & 0xFFFFFFFF  

    # Reverse Swap 1-bit
    y = ((y & 0x55555555) << 1) | ((y & 0xAAAAAAAA) >> 1)

    # Reverse Swap 2-bits
    y = ((y & 0x33333333) << 2) | ((y & 0xCCCCCCCC) >> 2)

    # Reverse Swap nibbles
    y = ((y & 0x0F0F0F0F) << 4) | ((y & 0xF0F0F0F0) >> 4)

    # Byte swap
    y = ((y & 0x000000FF) << 24) | \
        ((y & 0x0000FF00) << 8)  | \
        ((y & 0x00FF0000) >> 8)  | \
        ((y & 0xFF000000) >> 24)

    return y

def parse_hex(value_str):
    try:
        value_str = value_str.strip().lower()
        if value_str.startswith("0x"):
            value_str = value_str[2:]
        if len(value_str) > 8:
            raise ValueError("Input exceeds 32 bits.")
        return int(value_str, 16)
    except ValueError as ve:
        print(f"Error: Invalid hexadecimal input. {ve}")
        sys.exit(1)

def main():
    print("=== Encryption and Decryption Utility ===")
    print("This script encrypts a 32-bit hexadecimal value and then decrypts it to verify correctness.\n")
    
    # Prompt the user for input
    user_input = input("Enter a 32-bit hexadecimal value (e.g., 0x12345678): ").strip()
    
    # Parse the input
    input_value = parse_hex(user_input)
    
    print(f"\nOriginal Input Value : 0x{input_value:08X}")
    
    # Encrypt the input
    encrypted = encrypt(input_value)
    print(f"Encrypted Value     : 0x{encrypted:08X}")
    
    # Decrypt the encrypted value
    decrypted = decrypt(encrypted)
    print(f"Decrypted Value of the encrypted     : 0x{decrypted:08X}")

    # decrypt the original input
    decrypted_original = decrypt(input_value)
    print(f"Decrypted Value of the original input: 0x{decrypted_original:08X}")

if __name__ == "__main__":
    main()
