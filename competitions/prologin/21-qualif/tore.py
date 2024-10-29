from math import *
from matplotlib import cm
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np

#Ce programme affiche un tore en 3D

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

theta = np.linspace(0, 2 * np.pi, 20)   #Liste de 20 points entre 0 et 2 pi
phi = np.linspace(0, 2 * np.pi, 20)     #Liste de 20 points entre 0 et 2 pi

# #Fonction du tore en 3D de petit rayon 0.15 et de grand rayon 1
X = np.outer((1 + 0.15 * np.cos(phi)), np.cos(theta))
Y = np.outer((1 + 0.15 * np.cos(phi)), np.sin(theta))
Z = np.outer(np.sin(phi), 0.15 * np.ones(np.size(theta)))

# Dessin d'un plan
x2 = np.linspace(0, 8, 20)
y2 = np.linspace(0, 8, 20)
z2 = [0 for i in range (20)]

ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap='viridis')
# ax.plot_surface(x2, y2, z2)
ax.set_zlim3d(-0.45,0.45)
plt.show()