x=  [5.1, 5.6, 6.8, 5.9, 4, 5.6, 6.6, 6.7, 5.2, 4.5]
y = [5.4,5.6, 6.3, 6.1, 4.7, 5.1, 6.6, 6.8, 4.6, 4.1]
n = len(x)
assert n == len(y)

moyX = sum(x)/len(x)
moyY = sum(y)/len(y)
print (f"Moyenne x : {moyX} | moyenne y : {moyY}")

devsqX, r, devsqY = 0, 0, 0
for i in range (n) :
    r += (x[i]-moyX)*(y[i]-moyY)
    devsqX += (x[i]-moyX)**2
    devsqY += (y[i]-moyY)**2
print (f"Devsq x : {devsqX} | devsq y : {devsqY}")
print (f"r : {r}")
print (n)
varX, varY = 0, 0
b0 = moyY - moyX*b1
print ()