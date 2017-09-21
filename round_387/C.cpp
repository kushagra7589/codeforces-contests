#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define F first 
#define S second

vector< ll > occupied;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q; 
	occupied.resize(n+1);
	for(int i=1; i<=n; i++)
		occupied[i] = 0;
	while(q--)
	{
		ll t, k, d;
		cin >> t >> k >> d;
		ll sum = 0;
		ll cnt = 0;
		int i = 1;
		while(cnt < k && i <= n)
		{
			if(occupied[i] < t)
			{
				cnt += 1;
				sum += i;
			}
			i++;
		}
		if(cnt == k)
		{
			cnt = 0;
			i = 1;
			while(cnt < k && i <= n)
			{
				if(occupied[i] < t)
				{
					cnt += 1;
					// sum += i;
					occupied[i] = t + d - 1;
				}
				i++;
			}
				cout << sum << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}