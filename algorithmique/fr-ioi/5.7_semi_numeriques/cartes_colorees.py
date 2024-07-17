from colors import *

n = nbColors()
req = list(range(1, n+1))
res = question(req, n)
currSum = res

def ask(req, n, currSum):
    global res
    res += currSum - question(req, n)
    if n > 1 :
        for i in range (n) :
            tmp = req.copy()
            del tmp[i]
            ask(tmp, n-1, question(tmp, n-1)-currSum)

ask(req, n, currSum)
answer(res)