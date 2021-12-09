
f = open("input").read()

m = []
for l in f.split('\n'):
    if len(l) > 1:
        a = []
        for i in l:
            a.append(ord(i)-ord('0'))
        m.append(a)
        
ans =[]
for i in range(0,100):
    for j in range(0,100):
        if i > 0:
            if m[i][j] >= m[i-1][j]:
                continue
        if i < 99:
            if m[i][j] >= m[i+1][j]:
                continue
        if j > 0:
            if m[i][j] >= m[i][j-1]:
                continue
        if j < 99:
            if m[i][j] >= m[i][j+1]:
                continue
            

        ans.append(m[i][j])

sum =0
for i in ans:
    sum+=i+1
print(sum)


        

