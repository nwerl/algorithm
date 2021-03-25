N = int(input())

def isPrime(inp):
    if inp == 1:
        return False
    i = 2
    while i*i<=inp:
        if inp%i == 0:
            return False
        i = i+1

    return True

MAX = 1004000

for i in range(N, MAX):
    if isPrime(i) == True and str(i) == str(i)[::-1]:
        print(i)
        break