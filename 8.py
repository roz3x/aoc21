f = open("input", "r").read()

lengths = [2, 4, 3, 7 ]
uniqitems = {
    2: 1,
    4: 4,
    3: 7,
    7: 8,
}

sum = 0

for l in f.split('\n'):
    if len(l) > 1:
        digit = {}
        s = l.split('|')[0]
        k = l.split('|')[1]
        for i in s.split(' '):
            if len(i) in uniqitems:
                digit[uniqitems[len(i)]] = i
        
        onecnt = {}
        fourcnt = {}
        fives = []
        for i in s.split(' '):
            if len(i) == 6:
                if i not in  onecnt:
                    onecnt[i] = 0
                for c in i:
                    if c in digit[1]:
                        onecnt[i]+=1
            elif len(i) == 5:
                fives.append(i)
        for i in onecnt:
            if onecnt[i] == 1:
                digit[6] = i
            elif onecnt[i] == 2:
                if i not in fourcnt:
                    fourcnt[i] = 0
                for j in digit[4]:
                    if j in i:
                        fourcnt[i]+=1

        for i in fourcnt:
            if fourcnt[i] == 4:
                digit[9] = i
            else:
                digit[0] = i

            
        onecnt = {}
        for i in fives:
            if i not in onecnt:
                onecnt[i] = 0
            for c in digit[1]:
                if c in i:
                    onecnt[i]+=1

        sixcnt  = {}
        for i in fives:
            if onecnt[i] == 2:
                digit[3] = i
            else:
                if i not in sixcnt:
                    sixcnt[i] =0
                for c in digit[6]:
                    if c in i:
                        sixcnt[i]+=1

        for i in sixcnt:
            if sixcnt[i] == 5:
                digit[5] = i
            else:
                digit[2] = i
        
        inv_digit = {}
        for i in digit:
            inv_digit[''.join(sorted(digit[i]))] = i

        num = 0
        for i in k.split(' '):
            if len(i) > 1:
                n = ''.join(sorted(i))
                num = num*10 + inv_digit[n]
        sum += num


print(sum)
        
                    


            



