import os

def xor_decrypt(input_filepath, output_filepath):
    try:
        with open(input_filepath, 'rb') as infile:
            filesize = os.path.getsize(input_filepath)
            
            buffer = bytearray(infile.read())

            for i in range(filesize - 2, -1, -1):
                buffer[i] ^= buffer[i + 1]

        with open(output_filepath, 'wb') as outfile:
            outfile.write(buffer)

        print(f"Decryption successful. Output written to {output_filepath}")

    except FileNotFoundError:
        print("Failed to open input file")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    input_filepath = input("Enter the path of the file to decrypt: ")
    output_filepath = input("Enter the path for the decrypted output file: ")

    xor_decrypt(input_filepath, output_filepath)
