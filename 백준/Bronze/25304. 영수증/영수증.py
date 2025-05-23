target = int(input())
N  = int(input())
sum_price = 0
for i in range(0,N):
    price,num = map(int,input().split())
    sum_price += price * num
if target == sum_price:
    print('Yes')
else:
    print('No')