from scapy.all import *

def extract_reordered_png(pcap_file, port, output_file):
    # Read the pcapng file
    packets = rdpcap(pcap_file)

    # List to store tuples of (time, payload)
    packet_data = []

    # Extract the time of the first packet as the reference time
    random.seed(1727768037)
    # Extract packets sent to the specified port
    for packet in packets:
        if TCP in packet and packet[TCP].dport == port:
            payload = bytes(packet[TCP].payload)
            if payload:
               packet_data.append(payload)

    t = list(range(len(packet_data)))
    random.shuffle(t)

    final = [0] * len(packet_data)

    for i in range(len(packet_data)):
        final[t[i]] = packet_data[i]

    # Reconstruct the PNG file from the sorted payloads
    png_data = b''.join(final)

    # Write the reconstructed PNG data to the output file
    with open(output_file, 'wb') as f:
        f.write(png_data)

    print(f"PNG file successfully reconstructed and saved as {output_file}")

# Usage
pcap_file = 'cap.pcapng'  # Path to the pcapng capture file
output_file = 'reconstructed_image.png'  # Output PNG file path
port = 12345  # The port on which the PNG data was transmitted

# Reconstruct the PNG file
extract_reordered_png(pcap_file, port, output_file)
