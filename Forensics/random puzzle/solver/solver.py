from scapy.all import *

def extract_reordered_png(pcap_file, port, output_file):
    packets = rdpcap(pcap_file)

    packet_data = []

    random.seed(1727768037)
    for packet in packets:
        if TCP in packet and packet[TCP].dport == port:
            payload = bytes(packet[TCP].payload)
            if payload:
               packet_data.append(payload)
    print(len(packet_data))
    t = list(range(len(packet_data)))
    random.shuffle(t)

    final = [0] * len(packet_data)

    for i in range(len(packet_data)):
        final[t[i]] = packet_data[i]

    png_data = b''.join(final)

    with open(output_file, 'wb') as f:
        f.write(png_data)

    print(f"PNG file successfully reconstructed and saved as {output_file}")

pcap_file = 'cap.pcapng'
output_file = 'reconstructed_image.png'
port = 12345

extract_reordered_png(pcap_file, port, output_file)
