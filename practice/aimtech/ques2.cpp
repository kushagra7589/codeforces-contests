#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

vll coord;

int main()
{
	ios_base::sync_with_stdio(false);
	ll a, n;
	cin >> n >> a;
	ll x;
	for(int i=0; i<n; i++)
	{
		cin >> x;
		coord.pb(x);
	}
	ll ans = 0;
	sort(coord.begin(), coord.end());
	if(n==1)
	{
		ans = 0;
		cout << ans << endl;
		return 0;
	}
	if(a < coord[0])
	{
		ans = coord[n-2] - a;
	}
	else if(a > coord[coord.size()-1])
	{
		ans = a - coord[1];
	}
	else
	{
		if(a - coord[0] < coord[n-1] - a)
		{
			if(a >= coord[n-2])
			{
				ans = a - coord[0];
			}
			else
			{
				ans = 2 * (a - coord[0]);
				ans += max((ll)0, coord[n-2] - a); 
			}
		}
		else
		{
			if(a <= coord[1])
			{
				ans = coord[n-2] - a;
			}
			else
			{
				ans = 2 * (coord[n-1] - a);
				ans += max((ll)0, a - coord[1]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}