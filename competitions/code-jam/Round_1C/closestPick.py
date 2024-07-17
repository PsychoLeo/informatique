def solve():
    N, K = map(int, cin().split())
    l = list(map(int, cin().split()))
    p = 0
    l.sort() # On trie les tickets
    delta = [l[0]-1] # Partie gauche
    delta2 = []

    for first, second in zip(l, l[1:]):
        delta.append((second-first)//2)
        delta2.append(second-first-1)

    delta.append(K-tickets[-1]) # Partie droite
    delta.sort(reverse=True)
    delta2.sort(reverse=True)
    # 2 min :
    try :
    	return max(delta[0]+delta[1], delta2[0])/K
    except :
    	return (delta[0]+delta[1])/K

if __name__ == '__main__':
    import sys
    
    cin = sys.stdin.readline 
    cout = sys.stdout.write
    
    nbTests = int(input())

    for t in range(1, nbTests+1):
        cout(f"Case #{t}: {solve()}\n")


