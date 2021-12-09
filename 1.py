
v = []

while True:
    try: 
        v.append(int(input()))
    except:
        break

cnt= 0
for i in range(1, len(v)):
    if v[i] > v[i-1]:
        cnt+=1


print(cnt)
