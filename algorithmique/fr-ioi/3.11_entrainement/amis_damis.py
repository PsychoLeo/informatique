import sys

def read():
    return sys.stdin.readline().strip()

def main():
    start = int(read())
    n = int(read())
    neighbors = []
    isFriend = [0]*65000
    isFriend[start] = 3
    r = 0
    for i in range (n) :
        x, y = map(int, read().split())
        if x == start :
            isFriend[y] = 2
        elif y == start :
            isFriend[x] = 2
        else :
            neighbors.append((x, y))
    for x, y in neighbors :
        if isFriend[x] == 2 and isFriend[y] == 0 :
            isFriend[y] = 1
            r += 1
        elif isFriend[y] == 2 and isFriend[x] == 0 :
            # If links friend and friend of friend
            # and that friend of friend has not been visited
            isFriend[x] = 1
            r += 1
    print (r)
    

main()