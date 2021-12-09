
f = open("input").read()

N = 100
m = []
for l in f.split('\n'):
    if len(l) > 1:
        a = []
        for i in l:
            a.append(ord(i)-ord('0'))
        m.append(a)
        
done = [[False for i in range(0, N)] for j in range(0,N)]
found = [[0 for i in range(0, N)] for j in range(0,N)]


def recur(i , j, k):
    if i < N and i>=0 and j < N and j >=0 :
        if not (done[i][j] or m[i][j] == 9):
            done[i][j] = True
            found[i][j] = k

            recur(i-1,j, k)
            recur(i+1,j, k)
            recur(i, j-1,k)
            recur(i, j+1,k)


cnt = 1
for i in range(0, N):
    for j in range(0,N):
        if not done[i][j]:
            if m[i][j] != 9:
                recur(i,j,cnt)
                cnt+=1


print(found[1:3])

lu = {}

for i in found:
    for j in i:
        if j != 0:
            if j not in lu:
                lu[j] = 0
            else:
                lu[j]+=1


#sum = 1
#for i in lu:
#    sum *= lu[i]
#print(sum)

