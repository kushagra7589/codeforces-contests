#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll max1(ll a, ll b)
{
	return (a>b)?a:b;
}

int main()
{
	ll b, d, s;
	cin >> b >> d >> s;
	multiset<ll> ans;
	ans.insert(b);
	ans.insert(d);
	ans.insert(s);
	ll third = *ans.begin();
	ll second = *(++ans.begin());
	ll maxim = *(++(++ans.begin()));
	// cout << maxim << " " << second << " " << third << endl;
	ll res = 0;
	second += 1;
	third += 1;
	res += max1(0L, maxim - second);
	res += max1(0L, maxim - third);
	cout << res << endl;
}