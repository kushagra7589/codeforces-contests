base = int(input())
number = input()
n = i = len(number)-1;
ans = power = 0
while(n >= 0):
	i = n;
	while(i >= 0 and int(number[i:n+1]) < base):
		i -= 1
	while(i < n-1 and number[i+1] == '0'):
		i += 1
	ans += int(number[i+1:n+1]) * (base ** power) 
	n = i;
	power += 1;
print(ans)