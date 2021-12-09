
f = open("input", "r").read()

a = [0 for i in range(0,9)]
for i in f.split(','):
    a[int(i)]+=1

    
for t in range(0, 256):
    tmp = a[0]
    for i in range(1, 9):
        a[i-1]  = a[i]
    a[6] += tmp
    a[8] = tmp


print(sum(a))

