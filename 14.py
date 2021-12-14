

a = "BVBNBVPOKVFHBVCSHCFO"


mappings = {}
f = open("input").read()
for i in f.strip().split('\n'):
    i,j = i.split(' -> ')
    mappings[i] = j




magic = {}
for i in range(1, len(a)):
    k = a[i-1:i+1]
    print(k)
    if  k in magic:
        magic[k] += 1
    else:
        magic[k] = 1

for tt in range(0, 40):
    nm = {}
    for i in magic:
        if i in mappings:
            f = i[0] + mappings[i]
            s = mappings[i] + i[1]
            if f in nm:
                nm[f] += magic[i]
            else:
                nm[f] = magic[i]
            if s in nm:
                nm[s] += magic[i]
            else:
                nm[s] = magic[i]
    magic = nm

    
freq = {}
for i in magic:
    for j in i:
        if j not in freq:
            freq[j] = magic[i]
        else:
            freq[j] += magic[i]

for i in freq:
    if freq[i]%2 == 1:
        freq[i]+=1
        freq[i] = int(freq[i]/2)
    else:
        freq[i] = int(freq[i]/2)

    
m , M = 1000000000000000000000 , -1
for i in freq:
    m , M= min(m, freq[i]), max(M, freq[i])
print(M-m)

