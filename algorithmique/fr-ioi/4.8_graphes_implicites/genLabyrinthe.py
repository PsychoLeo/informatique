import random

def genLaserPath():
    MAXLIMIT = 1000
    height = MAXLIMIT
    width = MAXLIMIT
    grid = [['.']*width for _ in range (height)]
    for i in range (height) :
        for j in range (width) :
            r = random.random()
            if r < 0.15 :
                grid[i][j] = random.choice(['\\', '/'])
    with open('generatedPath', 'w') as f :
        f.write(str(height) + ' ' +str(width)+"\n")
        for i in grid :
            f.write(''.join(i)+'\n')

genLaserPath()