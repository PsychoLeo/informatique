import sys

def read():
    return sys.stdin.readline().strip()

def vacances_spatiales(p, d, mn, calendar):
    """
    :param p: le nombre de jours durant lesquels Chewbacca peut partir
    :type p: int
    :param d: le nombre de jours total minimun que Chewie veut passer avec sa famille
    :type d: int
    :param mn: le minimum de jours consécutifs pour un voyage
    :type mn: int
    :param calendar: les jours de la période donnée
    :type calendar: list[int]
    retourne 0 s'il ne peut partir en vacances assez et 1 s'il peut
    """
    if p < d or calendar.count(0) < d: # if impossible to leave
        return 0
    numDays = len(calendar)
    possible = 0
    i = 0
    while i < numDays :
        successifs = 0
        while i < numDays and calendar[i] == 0 :
            i += 1
            successifs += 1
            if successifs >= mn :
                while i < numDays and calendar[i] == 0 :
                    successifs += 1
                    i += 1
                possible += successifs
        i += 1
    return int(possible>=d)
        


if __name__ == '__main__':
    p = int(input())
    d = int(input())
    mn = int(input())
    calendar = list(map(int, read().split()))
    print(vacances_spatiales(p, d, mn, calendar))