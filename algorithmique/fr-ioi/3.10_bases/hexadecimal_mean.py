# def tableMult(n) :
#     l = [[bin(i*j)[2:] for j in range (1, n+1)] for i in range (1, n+1)]
#     for i in l :
#         print ('\t'.join(i))
    
# n = int(input())
# tableMult(n)

n = int(input(), 16)
r = c = 0

for i in range (n):
    r += int(input(), 16)
    c += 1
print (hex(r//c)[2:].upper())
