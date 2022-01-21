import socket

HOST = 'www.google.com'
PORT = 80

print('Creating socket...')
# create a socket object
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print('Socket created.')

print('Connection with remote host.')
s.connect((HOST, PORT))
print('Connection ok.')

s.send(b'GET /index.html HTML/1.1\r\n\r\n') #faz a transferencia de dados
while True:
    data = s.recv(4096).decode() #pega o dado ecoado
    print(data)
    if not data:
        print('Closing the socket.')
        s.close()
        break
