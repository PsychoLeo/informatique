# from math import sin, pi, tan
# import matplotlib.pyplot as plt

# def regressOrth () :
#     moyX = sum(x)/n
#     moyY = sum(y)/n
#     pas = 1e-2
#     alpha = -pi/2
#     bestSum = float("+inf")
#     while alpha < pi/2 :
#         p = moyY - tan(alpha)*moyX
#         res = testAlpha(alpha, p, n)
#         alpha += pas
#         if res < bestSum :
#             bestAlph = alpha
#             bestSum = res
#             bestP = p
#     print (f"Best sum of squares : {bestSum}")
#     print (f"Best tan(alpha) : {tan(bestAlph)} for alpha = {bestAlph*180/pi}°")
#     print (f"Best coordinate at origin : {bestP}")
#     plt.scatter (x, y, color="red")
#     plt.plot(x, [tan(bestAlph)*i + bestP for i in x], color="black")
#     plt.show()
		
# def testAlpha(alpha, p, n) :
#     somme = 0
#     for i in range (n) :
#         somme += (x[i] - (y[i]-p)/tan(alpha))**2
#     return somme*(sin(alpha)**2)
	
# if __name__ == "__main__" :
# 	n = int(input())
# 	x, y = [], []
# 	for i in range (n) :
# 		xi, yi = map(int, input().split())
# 		x.append(xi)
# 		y.append(yi)
# 	regressOrth()


from math import sin, pi, tan

def regressOrth () :
    moyX = sum(x)/n
    moyY = sum(y)/n
    pas = 1e-3
    alpha = -pi/2
    bestSum = float("+inf")
    while alpha < pi/2 :
        p = moyY - tan(alpha)*moyX
        res = testAlpha(alpha, p, n)
        alpha += pas
        if res < bestSum :
            bestSum = res
    return bestSum
		
def testAlpha(alpha, p, n) :
    somme = 0
    for i in range (n) :
        somme += (x[i] - (y[i]-p)/tan(alpha))**2
    return somme*(sin(alpha)**2)
	
if __name__ == "__main__" :
	n = int(input())
	x, y = [], []
	for i in range (n) :
		xi, yi = map(int, input().split())
		x.append(xi)
		y.append(yi)
	print(int(regressOrth()))