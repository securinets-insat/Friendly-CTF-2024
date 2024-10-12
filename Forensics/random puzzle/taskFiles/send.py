from scapy.all import *
import time
from math import floor

# Define the target IP and port
target_ip = "127.0.0.1"
target_port = 12345

# Path to the image file
image_path = "flag.png"

# Create the TCP connection (just send the data without handshaking)
src_port = 25000

# Use the current time as a random seed
random.seed(floor(time.time()))


# Read the image file and split it into chunks
chunk_size = 1024  # Fixed chunk size
chunks = []

with open(image_path, "rb") as img_file:
    while True:
        data_chunk = img_file.read(chunk_size)
        if not data_chunk:
            break
        chunks.append(data_chunk)

# Randomize the order of the chunks
random.shuffle(chunks)

# Send the randomized chunks over TCP
seq_num = random.randint(0, 10000)  # Random initial sequence number
for data_chunk in chunks:
    packet = IP(dst=target_ip) / TCP(sport=src_port, dport=target_port, flags='P', seq=seq_num) / Raw(load=data_chunk)
    send(packet)
    seq_num += len(data_chunk)  # Update sequence number for each chunk

print("Image sent successfully in randomized order!")
