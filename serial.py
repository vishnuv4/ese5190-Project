#!/usr/bin/python3

import serial
import time
ser = serial.Serial('COM3', baudrate=9600, stopbits=serial.STOPBITS_TWO, parity=serial.PARITY_NONE, dsrdtr=False, rtscts=False, xonxoff=False)
ser.reset_output_buffer()
i = 0
time.sleep(2)

with open("text.txt", "r") as file:
    for line in file:
        for char in line:
            while(ser.read() != b'n'):
                pass
            data = bytes(char, 'utf-8')
            ser.write(data)

data = bytes('|', 'utf-8')
ser.write(data)
ser.close()
