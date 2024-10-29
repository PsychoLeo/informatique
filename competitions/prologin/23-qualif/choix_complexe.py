adore = {input() for _ in range (6)}
deteste = {input() for _ in range (6)}
c = 0
for x in adore :
    if x not in deteste :
        c += 1
print(c)