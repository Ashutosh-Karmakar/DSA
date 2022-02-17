import serial
import time
import keyboard

i =0
k = 0
while 1:
    arduino = serial.Serial('com5', 9600)
    print('Established serial connection to Arduino')
    arduino_data = arduino.readline()
    print(arduino_data)

    decoded_values = str(arduino_data[0:len(arduino_data)].decode("utf-8"))
    list_values = decoded_values.split('x')
    l = int(list_values[0])
    print(l,type(l))
    if(l == 1):
        print("hekko")
        keyboard.send("alt+tab")
        k= 1

    arduino.close()
    print('Connection closed')
    print('<----------------------------->')

          



# import serial
# import time
# import schedule


# def main_func():
#     arduino = serial.Serial('com5', 9600)
#     print('Established serial connection to Arduino')
#     arduino_data = arduino.readline()
#     print(arduino_data)

#     decoded_values = str(arduino_data[0:len(arduino_data)].decode("utf-8"))
#     list_values = decoded_values.split('x')

#     for item in list_values:
#         list_in_floats.append(float(item))

#     print(f'Collected readings from Arduino: {list_in_floats}')

#     arduino_data = 0
#     list_in_floats.clear()
#     list_values.clear()
#     arduino.close()
#     print('Connection closed')
#     print('<----------------------------->')


# # ----------------------------------------Main Code------------------------------------
# # Declare variables to be used
# list_values = []
# list_in_floats = []

# print('Program started')

# # Setting up the Arduino
# schedule.every(0).seconds.do(main_func)

# while True:
#     schedule.run_pending()
    
