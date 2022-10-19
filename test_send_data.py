# # Importing Libraries
# import serial
# import time

# # Indicate the port connection between the device hosting the code and the Arduino board
# arduinoComPort = "/dev/ttyACM0"
# # Has to be the same baudRate with the code in the '.ino' file in order to take data from
# # its serial monitor
# baudRate = 9600
# # Initiating serial port
# arduino = serial.Serial(arduinoComPort, baudRate, timeout=1)

# def write_read(x):
#     arduino.write(bytes(x, 'utf-8'))
#     time.sleep(0.05)
#     data = arduino.readline()
#     return data

# while True:
# num = input("Enter a number: ") # Taking input from user
# value = write_read(num)
# print(type(num)) # printing the value

# num = input ("Enter number :")
# print(num)
# name1 = input("Enter namSe : ")
# print(name1)
  
# # Printing type of input value
# print ("type of number", type(num))
# print ("type of name", type(name1))

import serial
import time
arduino = serial.Serial("/dev/ttyACM1", 9600, timeout=1)
while True:
    i = input("input(left/right motor value): ").strip()
    if i == 'done':
        print("Finished")
        break
    arduino.write(i.encode(encoding='utf-8'))
    time.sleep(0.05)
    print(arduino.readline().decode())
arduino.close