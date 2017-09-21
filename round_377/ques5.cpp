#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define S second
#define F first

const int MAX_SIZE = 2e5+10;

multiset< pair<ll, int> > power;
vector< ll > socket(MAX_SIZE);
vector< ll > adapter(MAX_SIZE);
vector<int > connection(MAX_SIZE);

ll min1(ll a, ll b)
{
	return (a < b)?a:b;
}


int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	ll inp;
	for(int i=1; i<=n; i++)
	{
		cin >> inp;
		power.insert(mp(inp, i));
	}
	// sort(power.begin(), power.end());
	for(int i=1; i<=m; i++)
	{
		cin >> inp;
		socket[i] = inp;
	}
	ll total_adap = 0;
	ll total_comp = 0;
	for(int i=1; i<=n; i++)
		connection[i] = 0;

	for(int i=1; i<=m; i++)
		adapter[i] = 0;

	for(int i=1; i<=m; i++)
	{
		ll a = socket[i];
		ll adap = 0;
		while(a > 0)
		{
			multiset< pair<ll, int> >::iterator res = find_if(power.begin(), power.end(),
			    [&](const pair<ll, int>& val) -> bool {
			        return val.first == a;
			    });
			if(res != power.end())
			{
				connection[res->second] = i;
				auto next = res;
				res++;
				power.erase(res, next);
				break;
			}
			adap += 1;
			a = a/2;
		}
		if(a == 0)
		{
			adap = 0;
		}
		adapter[i] = adap;	
		total_adap += adap;
		total_comp += min1(1, adap);
	}
	cout << total_comp << " " << total_adap << endl;
	for(int i=1; i<=m; i++)
	{
		cout << adapter[i] << " ";
	}
	cout << endl;
	for(int i=0; i<=n; i++)
	{
		cout << connection[i] << " ";
	}
	cout << endl;
	return 0;
}