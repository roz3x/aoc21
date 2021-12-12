f = open("input").read()

import copy
paths = {}
for line in f.split():
    t , f = line.split('-')[0] , line.split('-')[1]
    if t not in paths:
        paths[t] = []
    if f not in paths:
        paths[f] = []
    paths[t].append(f)
    paths[f].append(t)


something = []
def recur(cur , done, taken):
    global unq
    for i in paths[cur]:
        if i == 'end':
            l = copy.deepcopy(done)
            something.append(l)
        elif i[0].islower():
            if i == "start":
                print("don")
            elif not taken:
                if done.count(i) == 1:
                    done.append(i)
                    recur(i, done, True)
                    done.pop()
                else:
                    done.append(i)
                    recur(i, done, taken)
                    done.pop()
            elif i not in done:
                done.append(i)
                recur(i, done, taken)
                done.pop()
        else:
            done.append(i)
            recur(i, done, taken)
            done.pop()



recur('start', ['start'], False)


print(len(something))





