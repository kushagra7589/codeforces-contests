	#include <bits/stdc++.h>

	using namespace std;

	#define ll long long
	#define pll pair<ll, ll>
	#define mp make_pair
	#define pb push_back
	#define F first 
	#define S second

	int main()
	{
		ios_base::sync_with_stdio(false);
		ll n, k;
		cin >> n >> k;
		vector< ll > temp;
		int t;
		vector<ll> dt;
		int allotted = 0;
		ll ans = 0;
		for(int i=1; i<=n; i++)
		{
			cin >> t;
			if(t < 0)
			{
				temp.pb(i);
				allotted += 1;
				ans += 2;
			}
		}
		if(allotted == 0)
		{
			cout << 0 << endl;
			return 0;
		}
		ll last = n - temp[temp.size() - 1];
		for(int i=1; i<temp.size(); i++)
		{
			dt.pb(temp[i] - temp[i-1] - 1);
		}
		sort(dt.begin(), dt.end());
		if(allotted > k)
		{
			cout << -1 << endl;
		}
		else
		{
			int i = 0;
			while(allotted <= k && i < dt.size())
			{
				allotted += dt[i];
				i++;
				ans -= 2;
			}
			if(allotted > k)
			{
				if(i != 0)
				{
					allotted -= dt[i-1];
					ans += 2;
				}
			}
			if(allotted + last <= k)
			{
				ans -= 1;
			}
			cout << ans << endl;
		}
		return 0;
	}