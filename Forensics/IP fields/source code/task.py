from scapy.all import IP, TCP, send

def send_packets_to_loopback(data, messages):
    # Loopback address (127.0.0.100)
    target_ip = "127.0.0.100"
    target_port = 12345  # You can choose any arbitrary port for TCP communication
    
    # Iterate over each character in the string
    for i, char in enumerate(data):
        # Get the ASCII value of the character
        ascii_val = ord(char)
        
        # Create an IP packet with the ASCII value of the character in the ID field
        ip_packet = IP(dst=target_ip, id=ascii_val)
        
        # Create a TCP packet with a corresponding message as payload
        if i < len(messages):
            tcp_packet = TCP(dport=target_port) / messages[i]
        else:
            tcp_packet = TCP(dport=target_port)  # No message if the list is exhausted
        
        # Combine IP and TCP packets
        packet = ip_packet / tcp_packet
        
        # Send the packet
        send(packet, verbose=0)
        
    print(f"Sent {len(data)} packets to {target_ip}.")

# Hardcoded string
data_string = "Securinets{Sens1t1ve_d4t4_0ver_IP??}"

# Messages to include in each packet for the conversation
messages = [
    "Hey, what's the password for the server again?",
    "Not something I can just say here.",
    "You can send it in a safe way, right?",
    "I’ve got a way, but you need to think outside the box.",
    "Outside the box? What do you mean?",
    "Just look closely. Sometimes, things aren't where you'd expect.",
    "Hmm, that sounds cryptic.",
    "Let's just say, the important info isn't always in plain sight.",
    "Okay, I'll figure it out... Should I be checking somewhere specific?",
    "The Ip packets got different fields don't they?",
    "Bro you know I'm not that good in networking.",
    "Just take a look at the fields you'll get it",
    "Ok same port?",
    "Yes."
]

# Send the packets
send_packets_to_loopback(data_string, messages)
