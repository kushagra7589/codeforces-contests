import sys
sys.stdin = open("important.in", 'r')
sys.stdout = open("important.out", 'w')
n = int(input())
print("Yes")
for i in range(n):
	a = input()
	if(i != n - 1):
		print(a[0] + "|~" + a[0] + "|", end ="")
	else:
		print(a[0] + "|~" + a[0])