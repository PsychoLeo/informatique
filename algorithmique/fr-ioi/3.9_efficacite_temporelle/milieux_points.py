import sys
# import pprint

def read() :
    return sys.stdin.readline().strip()

def main():
    nPoints = int(read())
    points = set()
    for i in range (nPoints) :
        x, y = map(int, read().split())
        points.add((x, y))
    findMids(points)

def findMids(points) :
    """Trying with set methods to gain efficiency
    => O(n^2) complexity"""
    links = {} # initializing points and links (to avoid A->B and B->A checked twice)
    tot = 0
    found = set()
    while points :
        current = points.pop()
        links[current] = points.copy()
    # pprint.pprint(links)
    for x, y in links :
        for X, Y in links[(x, y)] :
            midCoords = ((x+X)/2, (y+Y)/2)
            if midCoords in links and midCoords not in found:
                found.add(midCoords)
                tot += 1
    print (tot)

def findMidsIntersection (points) :
    middles = set()
    for x, y in points :
        for X, Y in points-{(x, y)} :
            midCoords = ((x+X)/2, (y+Y)/2)
            middles.add(midCoords)
    print (len(middles & points))


main()