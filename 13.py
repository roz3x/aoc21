
N = 802


folds = [
    [ 1 , 655],
    [ 0 , 447],
    [ 1 , 327],
    [ 0 , 223],
    [ 1 , 163],
    [ 0 , 111],
    [ 1 , 81],
    [ 0 , 55],
    [ 1 , 40],
    [ 0 , 27],
    [ 0 , 13],
    [ 0 , 6]
]


f = open("input").read()

m = [[0 for i in range(1400) ] for i in range(1400)]

np = set()
for ii in f.strip().split('\n'):
    x, y = ii.split(',')
    x, y = int(x), int(y)
    np.add((x,y))



for tt in folds:
    n = set()
    for i in np:
        x , y = i[0], i[1]
        if tt[0] == 1:
            t = tt[1]
            if  x >= t:
                n.add((t-(x-t), y))
            else :
                n.add((x,y))
        else:
            t = tt[1]
            if y >= t:
                n.add((x, t-(y-t)))
            else:
                n.add((x,y))
                
    np = n


m = [[0 for i in range(40)] for  i in range(40)]

for i in np:
    x , y = i
    m[x][y] = 1


for i in range(7):
    for j in range(39, -1, -1):
        if m[39-j][i]==1:
            print("$", end='')
        else:
            print('.', end='')

    print()


    


