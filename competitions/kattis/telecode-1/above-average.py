c = int(input())

for _ in range (c) :
    x = list(map(int, input().split()))[1:]
    avg = sum(x)/len(x)
    count_above = 0
    for moy in x :
        if moy > avg :
            count_above += 1
    percentage = 100*count_above/len(x)
    print(f"{round(percentage, 3):.3f}%")