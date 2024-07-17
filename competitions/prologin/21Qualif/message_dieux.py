taille = input()
nombres = [int(i) for i in input().split()]

alph = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'

if chr(nombres[0]) == chr(nombres[0]).upper() and chr(nombres[0]) in alph:
    position = alph.index(chr(nombres[0]))
    for num in nombres[1:] :
        position += num
        position %= 26
    print(alph[position])
else :
    print (' ')

