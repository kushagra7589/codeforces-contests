#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;

const int MAX_SIZE = 3e5 + 10;

set<pair<ll, ll>, greater<pair<ll, ll> > > A;  

int ans[MAX_SIZE];
ll C[MAX_SIZE];

int main() 
{
	ll n, k;
	cin >> n >> k;
	ll c;
	for(int i = 1; i <= n; i++)
	{
		cin >> C[i];
	}
	for(int i = 1; i <= k + 1; i++)
		A.insert({C[i], i});
	ll sum = 0;
	for(int i = 1; i <= n; i++)
	{
		auto a = *A.begin();
		A.erase(a);
		ans[a.S] = i + k;
		// cout << a.S << " " << a.F << endl;
		sum += a.F * (i + k - a.S);
		if(i + k + 1 <= n)
			A.insert({C[i + k + 1], i + k + 1});
	}
	cout << sum << endl;
	for(int  i = 1; i <= n; i++)
		cout << ans[i] << " ";
	return 0;
}