from turtle import *

colors = ['blue', 'green', 'yellow', 'orange', 'red', 'purple']
bgcolor('black')

def dessin (i=0) :
    if i < 180 :
        color(colors[i%6])
        forward(i)
        right(59)
        return dessin(i+1)

dessin()