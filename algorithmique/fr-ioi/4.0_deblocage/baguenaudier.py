def flip(n):
   cases[n] = not cases[n] # reversing current value
   print (n+1)

def solve (n) :
   if n == 1 :
      flip(0)
   elif n == 2 :
      flip(1)
      solve(1)
   else :
      solve (n-2)
      flip(n-1)
      rsolve(n-2)
      solve(n-1)

def rsolve (n) :
   if n == 1 :
      flip(0)
   elif n == 2 :
      rsolve(1)
      flip(1)
   else :
      rsolve(n-1)
      solve(n-2)
      flip(n-1)
      rsolve(n-2)


if __name__ == "__main__" :
    nbCases = int(input())
    cases = [True]*nbCases
    solve(nbCases)

# def hanoi (n, _from = 1, to = 3, by = 2) :
#     if n == 1 :
#         print (f"{_from} -> {to}")
#     else :
#         hanoi(n-1, _from, by, to)
#         print (f"{_from} -> {to}")
#         hanoi(n-1, by, to, _from)