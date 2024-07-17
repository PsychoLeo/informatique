from pyfirmata import Arduino, util

import time

carte = Arduino("/dev/ttyACM0")
acquisition = util.Iterator(carte)
acquisition.start ()

# http://ww2.ac-poitiers.fr/sc_phys/sites/sc_phys/IMG/pdf/programmer_carte_arduino_langage_python.pdf

# entree1 = carte.get_pin('a:0:i')

led13 = carte.get_pin('d:13:o')
time.sleep (1.0)

print ("Début du test")
for i in range (0, 10) :
    led13.write (1)
    time.sleep (0.5)
    led13.write (0)
    time.sleep (0.5)
print ("Fin du test")
carte.exit ()