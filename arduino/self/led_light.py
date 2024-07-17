from pyfirmata import Arduino, util
import time

carte = Arduino ('/dev/ttyACM0')
acquisition = util.Iterator (carte)
acquisition.start ()

sortie = carte.get_pin ('d:10:o')
time.sleep (1.0)

sortie.write (True)
time.sleep (4)
sortie.write (False)

carte.exit ()