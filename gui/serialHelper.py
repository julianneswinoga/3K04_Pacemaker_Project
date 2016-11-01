import sys
import glob
import serial

def serial_ports():
    if sys.platform.startswith('win'):
        ports = ['COM%s' % (i + 1) for i in range(256)]
    elif sys.platform.startswith('linux') or sys.platform.startswith('cygwin'):
        # this excludes your current terminal "/dev/tty"
        ports = glob.glob('/dev/tty[A-Za-z]*')
    elif sys.platform.startswith('darwin'):
        ports = glob.glob('/dev/tty.*')
    else:
        raise EnvironmentError('Unsupported platform')

    result = []
    for port in ports:
        try:
            s = serial.Serial(port)
            s.close()
            result.append(port)
        except (Exception):
            pass
    return result
	
def open_port(port, baud = 9600, timeout = None):
	ser = serial.Serial()
	ser.port = port
	ser.baudrate = baud
	ser.timeout = timeout
	ser.open()
	return ser

if __name__ == '__main__':
    print serial_ports()