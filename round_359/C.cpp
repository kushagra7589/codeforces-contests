#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
vector<ll> N, M;

vector<ll> base7(ll a)
{
	vector<ll> ans;
	while(a > 0)
	{
		ans.pb(a % 7);
		a /= 7;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

ll npr(ll n, ll r)
{
	ll ans = 1;
	for(ll i = n; i > n - r; i--)
	{
		ans *= i;
	}
	return ans;
}

ll dp(int l1, int r1, int l2, int r2, ll fixed)
{
	cout << "l1 = " << l1 << " r1 = " << r1 << " l2 = " << l2 << " r2 = " << r2 << " fixed = " << fixed << endl;
	if(l1 == r1 && l2 == r2)
		return 0;
	else if(l1 == r1)
	{
		ll ans = M[l2] * npr(6 - fixed, r2 - l2 - 1);
		cout << ans << endl;
		return ans + dp(l1, r1, l2+1, r2, fixed+1);
	}
	else if(l2 == r2)
	{
		ll ans = N[l1] * npr(6 - fixed, r1 - l1 - 1);
		cout << ans << endl;
		return ans + dp(l1 + 1, r1, l2, r2, fixed + 1);
	}
	else
	{
		ll ans = (min(N[l1], M[l2]))*(max(N[l1], M[l2])-1)*(npr(5 - fixed, r1 - l1 + r2 - l2 - 2));
		cout << ans << endl;
		return ans + dp(l1+1, r1, l2, r2, fixed+1) + dp(l1, r1, l2+1, r2, fixed+1) + dp(l1+1, r1, l2+1, r2, fixed+2);
	}
}

int main()
{
	ll n, m;
	cin >> n >> m;
	N = base7(n-1);
	M = base7(m-1);
	if(N.size() + M.size() > 7)
	{
		cout << 0;
		return 0;
	}
	cout << dp(0, N.size(), 0, M.size(), 0) << endl;
}