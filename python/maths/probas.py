import matplotlib.pyplot as plt

def anniv(n) :
    x = 1
    for i in range (n) :
        x *= (365-i)
    x = x/(365**n)
    return x

x = []
y = []

for n in range (1, 50) :
    p = anniv(n)
    x.append(n)
    y.append(p)

plt.plot(x, y)
plt.show()

