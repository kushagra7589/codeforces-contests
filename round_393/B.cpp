#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

ll firstN(ll x, ll y)
{
	if(x <= y)
		return ((y * (y + 1))/2) - (((y-x)*(y-x+1))/2);
	else
		return ((y * (y + 1))/2) + (y-x);
}

ll binary_S(ll n, ll m, ll k)
{
	ll l = 1;
	ll u = m;
	ll ans;
	while(l <= u)
	{
		ll mid = (l+u)/2;
		// cout << "l = " << l << " u = " << u << " mid = " << mid << endl;
		if(firstN(n-k, mid-1) + firstN(k-1, mid-1) +mid <= m)
		{
			l = mid + 1;
			ans = mid;
		}
		else
			u = mid;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m , k;
	cin >> n >> m >> k;
	cout << binary_S(n, m, k) << endl;
	return 0;
}