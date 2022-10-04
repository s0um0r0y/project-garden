import serial
serialcomm=serial.Serial('/dev/rfcomm0',38400,timeout=1)
#serialcomm.open()
serialcomm.reset_input_buffer()

for x in range(50):
    #initial setup
    serialcomm.write(bytes(str(x),'utf-8'))
    inVar=serialcomm.read_until().decode('latin-1')
    #output configutaion
    print("OUT: "+str(x)+" IN: "+str(inVar))
    ######
serialcomm.close()