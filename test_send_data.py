# Importing Libraries
import serial
import time

# Indicate the port connection between the device hosting the code and the Arduino board
arduinoComPort = "/dev/ttyACM0"
# Has to be the same baudRate with the code in the '.ino' file in order to take data from
# its serial monitor
baudRate = 9600
# Initiating serial port
arduino = serial.Serial(arduinoComPort, baudRate, timeout=1)

def write_read(x):
    arduino.write(bytes(x, 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data

while True:
    num = input("Enter a number: ") # Taking input from user
    value = write_read(num)
    print(value) # printing the value