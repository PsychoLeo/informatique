import math
import hashlib
from math import sin, cos, ceil, exp

class Encryption :

    def __init__(self) :
        self.key = "donnezmoidelapiensa"
        self.blocks = self.encrypt_key()

    def binexp(self, a, n, mod) :
        ans = 1
        while n :
            if n % 2 :
                ans = (ans * a) % mod
            a = (a * a) % mod
            n //= 2
        return ans
    
    def gcd(self, a, b) :
        return a if b == 0 else self.gcd(b, a%b)
    
    def inverse(self, x, mod) :
        assert self.gcd(x, mod) == 1
        return self.binexp(x, mod-2, mod)


    def encrypt_key(self) :
        hash = hashlib.sha512(self.key.encode()).digest()
        blocks = [b for b in hash]
        return blocks
    
    def f_encryption(i, j) :
        '''
        Input : a tuple of coordinates (i, j)
        Output : 
        '''
        k = exp(4 + cos(i^73))
        l = exp(5 + cos(j^43))
        return ceil(1000*sin(k)) + ceil(1000*sin(l))

    def encrypt_pixel(self, pos, rgb) :
        '''
        Encrypte le pixel 
        '''
        x, y = pos
        r, g, b = rgb


    def pixel_bij(self, x, y, w, h) :
        '''
        Renvoie f(x, y) où f est une bijection intéressante de l'ensemble E = [0, w-1] x [0, h-1] dans lui-même (à déterminer)
        Idéalement, on voudrait une fonction f (calculable facilement de manière déterministe) qui soit un peu chaotique
        '''
        # i = (x ^ (y + (w-1) // 2))
        # j = (y ^ (x + (h-1) // 2))
        return None
    
    def f_encr() :
        pass

    def f_decr() :
        pass
    

e = Encryption()
# print(e.blocks)

p = [13, 17, 23]

for n in range (1, 128) :
    ppown = [e.binexp(x, n, 128) for x in p]
    if ppown == [1, 1, 1]:
        print(n)
        break
