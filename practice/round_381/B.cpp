#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define mp make_pair
#define pb push_back
#define F first
#define S second

const int MAX_SIZE = 2e5+10;

vector< pair< ll, pll > > vertex(MAX_SIZE);
vector< ll > ans(MAX_SIZE, 0); 

int main()
{
	int n;
	cin >> n;
	ll x;
	for(int i=1; i<=n; i++)
	{
		cin >> x;
		vertex[i].F = x;
	}
	ll p, e;
	for(int i=2; i<=n; i++)
	{
		cin >> p >> e;
		vertex[i].S.F = p;
		vertex[i].S.S = e;
	}
	for(int i=n; i>1; i--)
	{
		ll sum = vertex[i].S.S;
		p = vertex[i].S.F;
		while(sum <= vertex[i].F)
		{
			ans[p] += 1;
			if(p == 1)
				break;
			sum += vertex[p].S.S;
			p = vertex[p].S.F;
		}
	}
	for(int i=1; i<=n; i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}