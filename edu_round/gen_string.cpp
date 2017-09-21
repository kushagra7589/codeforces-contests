#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE  = 1e7+10;
typedef long long ll;
ll arr[MAX_SIZE] = {0};

ll x, y;

ll count1 = 0;

// long long dp(int n, ll a) {
// 	count1 += 1;
// 	if(a >= n)
// 		return x * (a - n);
// 	else if(a == 0)
// 		return x + dp(n, a+1);
// 	else if(arr[a] == -1) {
// 		// if(a > 1)
// 		// 	arr[a] = min(min(y + dp(n, 2*a), x + dp(n, a+1)), dp(n, a-1));
// 		// else
// 		arr[a] = min(y + dp(n, 2*a), x + dp(n, a+1));
// 		cout << "a : " << a << " arr[a] : " << arr[a] << endl;
// 		return arr[a];
// 	}
// 	else
// 		return arr[a];
// } 

ll dp1(int n, ll a)
{
	count1 += 1;
	if(a == 0)
		return 0;
	else if(a > n)
		return x * (a-n);
	else if(arr[a] == -1) {
		if(a % 2 == 0)
			arr[a] = min(x + dp1(n, a-1), y + dp1(n, a/2));
		else{
			if(a == 1)
				arr[a] = x + dp1(n, a-1);
			else
				arr[a] = min(x + dp1(n, a-1), y+x+dp1(n, (a+1)/2));
		}
	}
	return arr[a];
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n >> x >> y;
	for(int i=0; i<=n; i++)
		arr[i] = -1;
	ll tim = 0;
	// arr[n] = 0;
	// arr[0] =
	tim += dp1(n, n);
	cout << tim << endl;
	// cout << count1 << endl;
	return 0;
}