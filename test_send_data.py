# Importing Libraries
import serial
import time

# Initiating serial port, integrating .ino file with this .py file
# The first entry is the USB-port the Arduino is connected to
# The second entry is the baudRate
arduino = serial.Serial("/dev/ttyACM1", 9600, timeout=1)

# Loop through and process input unless finish
while True:
    # Promp for input in terminal, take in string value
    i = input("input(left/right motor value): ").strip()
    # If the input is 'done', stop the loop,
    # not taking in more inputs
    if i == 'done':
        print("Finished")
        break
    # Transfer input in the form of bytes to the Arduino
    arduino.write(i.encode(encoding='utf-8'))
    # Processing time
    time.sleep(0.05)
    # Print the output of arduino-processed data
    print(arduino.readline().decode())
# Terminate connection with the Arduino after finished looping
arduino.close