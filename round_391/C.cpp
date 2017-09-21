#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second

const int MAX_SIZE = 1e5+10;

vector< set<ll> > diff;
vector< set<ll>  > row[MAX_SIZE];

map< ll,  ll > freq;

const int MAX_M = 1e6;

const int mod = 1e9+7;

ll factorial[MAX_M + 1];

int main(){
	ios_base::sync_with_stdio(false);
	factorial[1] = 1;
	for(ll i=2; i<=MAX_M; i++)
	{
		factorial[i] = (factorial[i-1] * i) % mod;
	}
	ll n, m;
	cin >> n >> m;
	ll g;
	ll x;
	for(int i=0; i<n; i++)
	{
		map< ll, set<ll> > other;
		cin >> g;
		for(int j=0; j<g; j++)
		{
			cin >> x;
			if(freq.find(x) == freq.end())
				freq[x] = 0;
			freq[x] += 1;
		}
		for(auto it : freq)
		{
			if(other.find(it.S) == other.end())
			{
				set< ll > temp;
				other[it.S] = temp;
			}
			other[it.S].insert(it.F);
		}
		freq.clear();
		for(auto it : other)
		{
			cout << it.F;
			for(auto jt : it.S)
			{
				cout << " -> " << jt;
			}
			cout << endl;
			row[i].pb(it.S);
		}
		other.clear();
	}
	cout << "yo " << endl;
	for(int i=0; i<n; i++)
	{
		cout << "1 ";
		for(auto j = row[i].begin(); j != row[i].end(); j++)
		{
			cout << "2 ";
			set<ll> temp;
			for(auto k = (*j).begin(); k != (*j).end(); k++)
			{
				cout << "3 ";
				for(auto x = diff.begin(); x != diff.end(); x++)
				{
					cout << "4 ";	
					if((*x).find(*k) != (*x).end())
					{
						(*j).erase(*k);
						(*x).erase(*k);
						temp.insert(*k);
						for(auto res = (*x).begin(); res != (*x).end(); res++)
						{
							cout << "5 ";
							if((*j).find(*res) != (*j).end())
							{
								(*j).erase(*res);
								(*x).erase(*res);
								temp.insert(*res);
							}
						}
						if(temp.size() != 0)
							diff.pb(temp);
						break;
					}
				}
			}
			if((*j).size() > 0)
				diff.pb(*j);
		}
	}
	for(auto it : diff)
	{
		for(auto jt : it)
		{
			cout << jt << " ";
		}
		cout << endl;
	}
	ll ans  = 1;
	for(auto it : diff)
	{
		ans = (ans * factorial[(it.size() == 0) ? 1 : it.size()]) % mod;
	}
	cout << ans << endl; 
	return 0;
}