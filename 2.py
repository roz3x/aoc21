deapth = 0
distance = 0
aim = 0
f = open("input", "r").read()
for line in f[:-1].split('\n'):
    l = line.split(' ')
    t , d = l[0], l[1]
    d = int(d)
    if t == "forward":
        distance += d
        deapth += aim * d
    elif t == "up":
        # deapth -= d
        aim -= d
    elif t == "down":
        # deapth += d
        aim += d




print(deapth)
print(distance)
print(distance * deapth)
