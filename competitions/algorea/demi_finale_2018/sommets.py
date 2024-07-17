nbSommets = int(input())
pred = int(input())
curr = int(input())
nexT = int(input())
r = 0
for i in range (nbSommets-3) :
    if curr > nexT and curr > pred :
        r += 1
    tmp = curr
    curr = nexT
    pred = tmp
    nexT = int(input())
if curr > nexT and curr > pred :
    r += 1
print(r)