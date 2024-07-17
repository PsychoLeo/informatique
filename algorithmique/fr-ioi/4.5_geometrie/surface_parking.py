from math import sqrt

def main():
    xa, ya = map(int, input().split())
    xb, yb = map(int, input().split())
    xc, yc = map(int, input().split())
    if xc-xb != 0 :
        m = (yc-yb)/(xc-xb)
        p = yb-m*xb
        xh = (xa+m*ya-m*p)/(1+m*m)
        yh = m*xh+p
        BC = sqrt((xc-xb)**2 + (yc-yb)**2)
        AH = sqrt((xh-xa)**2 + (yh-ya)**2)
        print (round(BC*AH))
    elif xa-xb != 0 :
        m = (ya-yb)/(xa-xb)
        p = ya-m*xa
        xh = (xc+m*yc-m*p)/(1+m*m)
        yh = m*xh+p
        AB = sqrt((xa-xb)**2 + (ya-yb)**2)
        CH = sqrt((xh-xc)**2 + (yh-yc)**2)
        print(round(AB*CH))
    else :
        if xa-xc == 0 :
            print (0); return
        m = (ya-yc)/(xa-xc)
        p = ya-m*xa
        xh = (xc+m*yc-m*p)/(1+m*m)
        yh = m*xh+p
        AC = sqrt((xa-xc)**2 + (ya-yc)**2)
        BH = sqrt((xh-xb)**2 + (yh-yb)**2)
        print(round(AC*BH))

main()