import serial
import time
#set up serial port
ser=serial.Serial(
port='COM3',
baudrate=9600,
timeout=1,
)

time.sleep(1.75)#doesn't work without this minimum delay, because set-up call resets

def motor_on(x):
    ser.write(x)
#encode int values to be sent over
i=1;
i_str=str(i)
i_encoded=i_str.encode('ascii')

#run
motor_on(i_encoded)
