L = list(map(int, input().split()))
a, b, c = L[0], L[1], L[2]
if ((a<b<=a+1 or a<c<=a+1) and ((c>=a+2 and c>=b+2)or(b>=a+2 and b>=c+2))):
	print("True")
else:
	print("False")