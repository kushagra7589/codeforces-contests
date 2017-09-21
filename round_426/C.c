#include <stdio.h>

typedef long long ll;

int cubes[(int)1e3 + 1];


ll gcd(ll a, ll b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i*i*i <= 1e9; i++)
		cubes[i - 1] = i*i*i;
	ll x, y;
	while(n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		x = a; y = b;
		ll sum = x + y;
		x = (x > y) ? x : y;
		ll X = x;
		y = sum - x;
		ll Y = y;
		ll g = gcd(x, y);
		x /= g;
		y /= g;
		// cout << y;
		if(g == 1 && X != 1 && Y != 1) {
			printf("No\n");
			continue;
		}
		ll num = x * x * y;
		ll den = x * y * y;
		if(X % num != 0 || Y % den != 0) {
			printf("No\n");
			continue;
		}
		ll rem1 = X / num;
		ll rem2 = Y / den;
		if(rem1 != rem2)
		{
			printf("No\n");
			continue;
		}
		ll l = 0;
		ll h = 1e3 + 1;
		int flag = 0;
		while(l < h) {
			ll mid = (l + h) /2;
			if(mid == rem1) {
				flag = 1;
				break;
			}
			else if(mid < rem1) {
				l = mid + 1;
			}
			else {
				h = mid - 1;
			}
		}
		if(flag)
				printf("No\n");
		else
			printf("Yes\n");
	}	
	return 0;
}