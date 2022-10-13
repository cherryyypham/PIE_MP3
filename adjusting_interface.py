# Importing Libraries
import serial
from pynput import Listener

# # Indicate the port connection between the device hosting the code and the Arduino board
# arduinoComPort = "/dev/ttyACM0"
# # Has to be the same baudRate with the code in the '.ino' file in order to take data from
# # its serial monitor
# baudRate = 9600
# # Initiating serial port
# arduino = serial.Serial(arduinoComPort, baudRate, timeout=1)

speed = 20
pressed = False

# def write_read(x):
#     arduino.write(bytes(x, 'utf-8'))
#     time.sleep(0.05)
#     data = arduino.readline()
#     return data
with Listener() as listener:
    listener.join()
    
def on_press(key):
    pass

def on_release(key):
    pass
# while True:
#     if keyboard.is_pressed('s'):
#         if not pressed:
#             speed += 1
#             # value = write_read(speed)
#             # print(value)
#             print(speed)
#             pressed = True

    # elif keyboard.is_pressed('-'):
    #     if not pressed:
    #         speed -= 1
    #         # value = write_read(speed)
    #         # print(value)
    #         print(speed)
    #         pressed = True
    # else:
    #     pressed = False
