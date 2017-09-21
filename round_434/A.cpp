#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

ll ten[9];

int main()
{
	ten[0] = 1;
	for(int i = 1; i < 9; i++)
	{
		ten[i] = ten[i - 1] * 10;
	}
	ll n, k;
	cin >> n >> k;
	ll p = n * ten[k];
	ll g = gcd(n, ten[k]);
	ll ans = p / g;
	cout << ans << endl;
	return 0;
}