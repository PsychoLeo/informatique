MAX = 10000

def valeursPrisesSomme () :
    visited = [False]*(MAX+1)
    for a in range (1, MAX+1) : 
        for k in range (2, MAX+1) :
            for j in range (2, MAX+1) :
                n = a*(1+k+k*j)
                if n < MAX :
                    visited[n] = True
                else :
                    break
    for i in range (MAX+1) : 
        if visited[i] == False :
            print(i)


valeursPrisesSomme()