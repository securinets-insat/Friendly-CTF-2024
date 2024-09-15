from scapy.all import *
import binascii

def extract_icmp_data(pcapng_file):
    packets = rdpcap(pcapng_file)
    fragments = []
    i=0
    for packet in packets:
        if packet.haslayer(ICMP) and packet.haslayer(Raw) and packet[ICMP].type != 0 and packet[IP].dst == '192.168.1.21' and packet[ICMP].id==i:
            raw_data = packet[Raw].load
            i+=1
            fragments.append(binascii.unhexlify(raw_data))

    reassembled_data = b''.join(fragments)
    return reassembled_data

def write_file(data, output_file):
    with open(output_file, 'wb') as f:
        f.write(data)

if __name__ == "__main__":
    pcapng_file = 'chall.pcapng' 
    output_file = 'output_file.zip' 
    
    data = extract_icmp_data(pcapng_file)
    write_file(data, output_file)
    
    print(f"Reconstructed file saved as {output_file}")
