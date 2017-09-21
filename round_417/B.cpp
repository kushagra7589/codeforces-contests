#include <bits/stdc++.h>

using namespace std;

#define fast_io() ios_base::sync_with_stdio(false);
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

vector<ll> costs;
vector<ll> prefix;

int main()
{
	int n;
	ll S;
	cin >> n >> S;
	costs.resize(n + 1);
	prefix.resize(n + 1);
	prefix[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		cin >> costs[i];
	}
	// sort(costs.begin(), costs.end());
	for(int i = 1; i <= n; i++)
	{
		prefix[i] = prefix[i - 1] + costs[i];
	}
	int l = 1, h = n + 1;
	vector<ll> sums;
	ll ans;
	ll get_sum = 0;;
	while(l < h)
	{
		sums.clear();
		ll mid = (l + h)/2;
		for(int i = 1; i <= n; i++)
		{
			sums.pb(costs[i] + i*mid);
		}
		sort(sums.begin(), sums.end());
		get_sum = 0;
		for(int i = 0; i < mid; i++)
		{
			get_sum += sums[i];
		}
		if(get_sum <= S)
		{
			l = mid + 1;
		}
		else
		{
			h = mid;
		}
	}
	sums.clear();
	ll a = l - 1;
	for(int i = 1; i <= n; i++)
	{
		sums.pb(costs[i] + i*a);
	}
	get_sum = 0;
	sort(sums.begin(), sums.end());
	for(int i = 0; i < a; i++)
	{
		get_sum += sums[i];
	}
	cout << a << " " << get_sum << endl;
	return 0;
}