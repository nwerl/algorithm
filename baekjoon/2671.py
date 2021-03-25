import re

p = re.compile('(100+1+|01)+')
n = input()
m = p.fullmatch(n)
if m == None:
    print("NOISE")
else:
    print("SUBMARINE")