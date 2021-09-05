from socket import socket, AF_INET, SOCK_DGRAM
import sys
import serial

HOST = ""
PORT = 8000

s = socket(AF_INET, SOCK_DGRAM)
s.bind((HOST, PORT))

ser = serial.Serial('/dev/ttyACM0', 9600)

try:
    while True:
        msg, addr = s.recvfrom(32)
        print(msg)
        ser.write(msg)
except KeyboardInterrupt:
    print("close")
    s.close()
    sys.exit()