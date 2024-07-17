from math import sqrt

# for mod in range (2, 25) :
#     print(f"Modulo {mod}")
#     for n in range (1, 100) :
#         r = 2**(n-1)*n+1
#         print(r% mod)
#     input()


def is_square(apositiveint):
    x = apositiveint // 2
    seen = set([x])
    while x * x != apositiveint:
        x = (x + (apositiveint // x)) // 2
        if x in seen:
            return False
        seen.add(x)
    return True

for n in range (1, 1000) :
    x = n*pow(2, n-1)+1
    if is_square(x) :
        print(n)
        