#!/usr/bin/python3
import serial
import time
ser = serial.Serial('COM4', baudrate=9600, stopbits=serial.STOPBITS_TWO, parity=serial.PARITY_NONE)
#ser = serial.Serial('/dev/ttyS3', baudrate=9600, stopbits=serial.STOPBITS_TWO, parity=serial.PARITY_NONE)
ser.reset_output_buffer()
i = 0
time.sleep(2)

print()
print('-----TEXT BEGIN-----')
with open("text.txt", "r") as file:
    for line in file:
        print(line, end='')

print('-----TEXT END-------')
print()
print('-----CHARACTERS-----------')
with open("text.txt", "r") as file:
    for line in file:
        for char in line:
            while(ser.read() != b'n'):
                pass
            data = bytes(char, 'utf-8')
            print(char, end='', flush=True)
            ser.write(data)

print('-----END OF CHARACTERS-----')
data = bytes('|', 'utf-8')
ser.write(data)
ser.close()
