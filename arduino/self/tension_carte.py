from pyfirmata import Arduino, util
import time

carte = Arduino ('/dev/ttyACM0')
acquisition = util.Iterator (carte)
acquisition.start ()

tension_A0 = carte.get_pin ('a:0:i')
time.sleep (1.0)

R1 = 3000
R2 = 1000

Umes = tension_A0.read()*5+(R1+R2)/R2
print (Umes, "V")

carte.exit ()