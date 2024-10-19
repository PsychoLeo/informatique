from heapq import heappop, heappush, heapify

class Solution :

    def binexp(self, a, n) :
        r = 1
        while n > 0 :
            if n % 2 == 1 :
                r = (r * a)
            a = (a * a)
            n //= 2
        return r

    def getFinalState(self, a, k, m) :
        n = len(a)
        MOD = int(1e9+7)
        if m == 1 :
            return a
        for i in range (n) :
            a[i] = [a[i], i]
        a.sort()
        for i in range (n-1) :
            # premiere etape en O(n log n)
            while m*a[i][0] <= a[i+1][0] :
                a[i][0] *= m
                k -= 1
        mult = self.binexp(m, k//n)
        for i in range (n) :
            a[i][0] *= mult
        k %= n
        heapify(a)
        for i in range (k) :
            x, j = heappop(a)
            x *= m
            heappush(a, [x, j])
        na = [None]*n
        for x, i in a :
            na[i] = x % MOD
        return na


                

            
s = Solution()
# print(s.getFinalState([2,1,3,5,6], 5, 2))
# print(s.getFinalState([100000,2000], 2, 1000000))
# print(s.getFinalState([2,5,2,2], 2, 2))
# print(s.getFinalState([1, 2, 5], 1, 2))
print(s.getFinalState([161209470], 56851412, 39846))