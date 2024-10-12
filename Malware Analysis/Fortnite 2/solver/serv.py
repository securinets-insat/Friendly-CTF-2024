import socket

def start_server(host='127.0.0.1', port=14789, buffer_size=1024):
    # Create a TCP/IP socket
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        # Bind the socket to the address and port
        server_socket.bind((host, port))
        # Listen for incoming connections
        server_socket.listen(5)
        print(f"Listening on {host}:{port}...")

        while True:
            # Accept a new connection
            client_socket, client_address = server_socket.accept()
            with client_socket:
                print(f"Connection from {client_address}")
                
                while True:
                    # Receive data from the client
                    data = client_socket.recv(buffer_size)
                    if not data:
                        break  # Break when no more data is received
                    print(f"Received: {data.decode('utf-8')}")

if __name__ == "__main__":
    start_server()
