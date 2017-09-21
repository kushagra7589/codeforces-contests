import math
# numbers = list(map(int, input().split()))

# n = numbers[0]
# k = numbers[1]
n = 2
k = 15000

current = int(math.sqrt(n))
rem = n - (current*current)
print(str(current)+".", end='')
num_out = current

for i in range(k):
	rem *= 100 
	current = num_out*20
	l = 0
	u = 10
	while(l < u):
		mid = (l+u)//2
		if((current+mid)*mid <= rem):
			l = mid+1
		else:
			u = mid
	ans = l-1
	current += ans
	rem = rem - (current*ans)
	num_out = num_out*10 + ans
	print(str(ans), end='')


