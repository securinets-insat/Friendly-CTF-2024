from scapy.all import rdpcap, IP, TCP

def extract_flag(pcap_file):
    packets = rdpcap(pcap_file)
    flag = ""

    for packet in packets:
        if packet.haslayer(IP) and packet.haslayer(TCP):
            if packet[TCP].dport == 12345:
                ip_id = packet[IP].id
                flag += str(chr(ip_id))

    print(f"Extracted flag: {flag}")

pcap_file = "cap.pcapng"

extract_flag(pcap_file)
