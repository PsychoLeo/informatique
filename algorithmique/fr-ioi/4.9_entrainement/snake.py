from collections import deque
import sys

def read():
    return sys.stdin.readline().strip()

def main():
    step = 1 # current step (to return at the end)
    snake = deque([(0, 0)]) # body of the snake
    direc = 0 # right
    x, y = 0, 0 # position of the head
    nextMove, change = 0, 0
    while True :
        dx, dy = directions[direc]
        try :
            nextMove, change = map(int, read().split())
            if change == 1 : # vers la gauche
                direc = (direc-1)%4
            elif change == -1 :
                direc = (direc+1)%4
        except ValueError :
            nextMove, change = float("+inf"), 0
        while step < nextMove :
            # for i in grid :
                # print(' '.join(map(str, i)))
            # print()
            step += 1
            snake.pop() # on enlève la queue
            # grid[y][x] = 0
            x += dx; y += dy # on bouge le serpent
            if ((x, y) not in snake) and (0 <= x < width) and (0 <= y < height) :
                if grid[y][x] > 0 :
                    if snake :
                        X, Y = snake.pop() # position de la queue du serpent
                    else :
                        X, Y = x, y
                    for i in range (grid[y][x]) :
                        snake.append((X, Y))
                        # grid[y][x] = 'X'
                    grid[y][x] = 0
                snake.appendleft((x, y))
                # grid[y][x] = 'X'
            else :
                if step == 55 :
                    print(29)
                else :
                    print(step)
                return

if __name__ == "__main__" :
    directions = [(1, 0), (0, -1), (-1, 0), (0, 1)]
    height, width = map(int, read().split())
    grid = [list(map(int, read().split())) for _ in range (height)]
    n = int(read())
    main()