from scapy.all import *

# Define the IP and port
target_ip = '127.0.0.1'
target_port = 11111
message = "flag{Thats it bro what are you doing here}"

# Create a TCP SYN packet to establish a connection
ip = IP(dst=target_ip)
syn = TCP(dport=target_port, flags='S', seq=1000)
syn_ack = sr1(ip/syn)  # Send SYN and receive SYN-ACK

# Create an ACK packet to complete the three-way handshake
ack = TCP(dport=target_port, flags='A', seq=syn_ack.ack, ack=syn_ack.seq + 1)
send(ip/ack)

# Send the data packet
data = TCP(dport=target_port, flags='PA', seq=syn_ack.ack, ack=syn_ack.seq + 1) / message
send(ip/data)

# Close the connection by sending a FIN packet
fin = TCP(dport=target_port, flags='FA', seq=syn_ack.ack + len(message), ack=syn_ack.seq + 1)
send(ip/fin)
