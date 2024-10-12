from scapy.all import *
import binascii

def fragment_data(data, max_size):
    return [data[i:i+max_size] for i in range(0, len(data), max_size)]

def send_icmp_fragments(destination, data, fragment_size=32):
    fragments = fragment_data(data, fragment_size)
    
    for i, fragment in enumerate(fragments):
        print(len(fragment))
        packet = IP(dst=destination,flags="DF")/ICMP()/Raw(load=fragment)
        packet[ICMP].id = i
        send(packet)
        print(f"Sent fragment {i+1}/{len(fragments)}")

if __name__ == "__main__":
    target = "192.168.1.3"
    with open('flag.zip', 'rb') as f:
        zip_data = f.read()
    data= binascii.hexlify(zip_data).decode()
    send_icmp_fragments(target, data.encode(), fragment_size=1400)
