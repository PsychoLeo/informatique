import math

def circle_center(A, B, C):
    D = 2 * (A[0] * (B[1] - C[1]) + B[0] * (C[1] - A[1]) + C[0] * (A[1] - B[1]))
    Ux = ((A[0]**2 + A[1]**2) * (B[1] - C[1]) + (B[0]**2 + B[1]**2) * (C[1] - A[1]) + (C[0]**2 + C[1]**2) * (A[1] - B[1])) / D
    Uy = ((A[0]**2 + A[1]**2) * (C[0] - B[0]) + (B[0]**2 + B[1]**2) * (A[0] - C[0]) + (C[0]**2 + C[1]**2) * (B[0] - A[0])) / D
    return (Ux, Uy)

def distance(P, Q):
    return math.hypot(P[0] - Q[0], P[1] - Q[1])

def polygon_vertices(A, B, C, n):
    O = circle_center(A, B, C)
    R = distance(O, A)
    angle_A = math.atan2(A[1] - O[1], A[0] - O[0])
    theta = 2 * math.pi / n
    vertices = []
    for i in range(n):
        angle = angle_A + i * theta
        x = O[0] + R * math.cos(angle)
        y = O[1] + R * math.sin(angle)
        vertices.append((x, y))
    return vertices


if __name__ == "__main__" :
    while True :
        n = int(input())
        if n == 0 :
            break
        A = list(map(float, input().split()))
        B = list(map(float, input().split()))
        C = list(map(float, input().split()))
        p = polygon_vertices(A, B, C, n)
        lox = float("inf")
        hix = float("-inf")
        loy = float("inf")
        hiy = float("-inf")
        for x, y in p :
            lox = min(lox, x)
            hix = max(hix, x)
            loy = min(loy, y)
            hiy = max(hiy, y)
        print((hix-lox)*(hiy-loy))