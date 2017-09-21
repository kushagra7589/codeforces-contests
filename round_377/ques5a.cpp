#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define S second
#define F first

const int MAX_SIZE = 2e5+10;

unordered_map<ll, set<int> > power;
multiset< pair<ll, int>  > sockets;
vector< ll > adapter(MAX_SIZE);
vector< int> connection(MAX_SIZE);

ll min1(ll a, ll b)
{
	return (a < b) ? a : b;
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
		power[inp].insert(i);
		connection[i] = 0;
	}
	for(int i=1; i<=m; i++)
	{
		cin >> inp;
		sockets.insert(mp(inp, i));
		adapter[i] = 0;
	}
	ll total_adap = 0;
	ll total_comp = 0;
	for(auto j : sockets)
	{
		int i = j.S;
		ll a = j.F;
		ll adap = 0;
		int flag = 0;
		while(a > 0)
		{	
			if(power.find(a) != power.end())
			{
				auto it = power[a].begin();
				connection[*it] = i;
				power[a].erase(it);
				if(power[a].empty())
					power.erase(a);
				total_comp += 1;
				flag = 1;
				break;
			}
			if(a == 1)
				break;
			adap += 1;
			a = (a+1)/2;
		}

		if(flag == 0)
			adap = 0;
		adapter[i] = adap;
		total_adap += adap;
	}
	cout << total_comp << " " << total_adap << endl;
	for(int i=1; i<=m; i++)
	{
		cout << adapter[i] << " ";
	}
	cout << endl;
	for(int i=1; i<=n; i++)
	{
		cout << connection[i] << " ";
	}
	cout << endl;
	return 0;
} 