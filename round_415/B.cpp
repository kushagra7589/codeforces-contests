#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

vector<ll> getter;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, f;
	cin >> n >> f;
	ll k, l;
	ll sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> k >> l;
		sum += min(k, l);
		if(l > k)
			getter.pb(min(k, l - k));
		else
			getter.pb(0);
	}
	sort(getter.begin(), getter.end());
	int x = getter.size();
	for(int i = x - 1, j = 0; j < f; i--, j++)
	{
		sum += getter[i];
	}
	cout << sum << endl;
	return 0;
}