import socket
import threading

HEADER = 64
PORT = 5060
SERVER = '192.168.0.106'#socket.gethostbyname(socket.gethostbyname())
ADDR = (SERVER,PORT)
FORMAT = 'utf-8'

server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
server.bind(ADDR)
DISCONNECT_MESSAGE = "!DISCONNECT"

def handle_client(conn,addr):
    print(f"[New Connection] {addr} connected")
    connected = True
    while connected:
        msg_length = conn.recv(HEADER).decode(FORMAT)
        msg_length = int(msg_length)
        msg = conn.recv(msg_length).decode(FORMAT)
        if msg == DISCONNECT_MESSAGE:
            connected = False
        print(f"[{addr}] {msg}")
    conn.close()
        
def start():
    server.listen()
    while True:
        conn , addr = server.accept()
        thread = threading.Thread(target = handle_client, args=(conn,addr))
        thread.start()
        print(f"[ACTIVE CONNECTION] {threading.activeCount() - 1}")
print(f"[STARTING] server is starting")
start()