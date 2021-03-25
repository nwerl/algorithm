n = int(input())
arr = [0]*10
while n:
    arr[int(n%10)]+=1
    n = int(n/10)

ans = ""
for i in range(1, len(arr)+1):
    while arr[-i]:
        arr[-i]-=1
        ans += str(10-i)

print(ans)