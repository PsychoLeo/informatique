from math import sqrt

def area(A, B, C):
    """
    Returns the area of the triangle ABC
    multiplied by 2 in order to neglect floating point numbers
    """
    return abs((B[0]-A[0])*(C[1]-A[1]) - (C[0]-A[0])*(B[1]-A[1]))

n = 1000
contain = 0 # number of triangles that contain the origin
for i in range (n) :
    x1, y1, x2, y2, x3, y3 = list(map(int, input().split()))
    A, B, C, O = (x1, y1), (x2, y2), (x3, y3), (0, 0)
    # Area formula
    if area(A, C, O) + area(B, C, O) + area(A, B, O) == area(A, B, C) :
        contain += 1
    
print(contain)