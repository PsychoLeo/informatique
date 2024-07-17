def isPandigital (a, b):
    prod = str(int(a)*int(b))
    entireNB = a+b+prod
    nbCount = [0]*10
    for i in (entireNB) :
        if int(i) > 9 or int(i) == 0 or nbCount[int(i)] > 0:
            return False
        else :
            nbCount[int(i)] = 1
    return len(set(entireNB)) == len(list(entireNB)) == 9

def main() :
    global found
    for a in range (1000) :
        for b in range (1000) :
            if (a*b not in found) and isPandigital(str(a), str(b)) :
                found.add(a*b)
    for a in range (100) :
        for b in range (10*1000) :
            if (a*b not in found) and isPandigital(str(a), str(b)) :
                found.add(a*b)


found = set()
main()
res = 0
print(found)
for i in found :
    res += i
print(res)