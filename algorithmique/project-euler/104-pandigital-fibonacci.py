import sys
sys.set_int_max_str_digits(1000000)
from copy import deepcopy



def mult(A, B) :
    a00, a01 = A[0]
    a10, a11 = A[1]
    b00, b01 = B[0]
    b10, b11 = B[1]
    return [[a00*b00 + a01*b10, a00*b01 + a01*b11],
            [a10*b00 + a11*b10, a10*b01 + a11*b11]]

def F(n) :
    return binexp(A, n-1)[0][0]


def binexp(M, n) :
    R = deepcopy(I)
    P = deepcopy(M)
    while (n) :
        if (n % 2) :
            R = mult(R, P)
        P = mult(P, P)
        n //= 2
    return R


def main(): 
    global i, f1, f0
    while True :
        # print(i)
        m = 0
        v = f1
        for _ in range (1, 10) :
            a = v % 10
            if a == 0 :
                break
            a -= 1
            if (1 << a) & m == 0 :
                m |= (1 << a)
            else :
                break
            v //= 10
        if m == obj :
            p = F(i)
            if sorted(str(p)[:9]) == s :
                print(i)
                # print(p)
                break
        i += 1
        f0, f1 = f1, (f0+f1) % MOD

def test() :
    print(f"F(541) : {F(541)}")
    print(f"F(2749) : {F(2749)}")

if __name__ == "__main__" :
    f0, f1 = 0, 1
    s = list("123456789")
    i = 1
    MOD = int(1e9)
    obj = 511

    A = [[1, 1], [1, 0]]
    I = [[1, 0], [0, 1]]

    # test()
    main()