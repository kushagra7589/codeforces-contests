#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define F first
#define S second

map<int, set<pair<ll, int> > > tshirts;
vector<ll> price;
vector<int> front,  back;
int main()
{
	ios_base::sync_with_stdio(false);
	int n; 
	cin >> n;
	price.resize(n);
	front.resize(n);
	back.resize(n);
	for(int i = 0; i < n ; i++)
	{
		cin >> price[i];
	}
	for(int i = 0; i < n ; i++)
	{
		cin >> front[i];
	}
	for(int i = 0; i < n ; i++)
	{
		cin >> back[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(tshirts.find(front[i]) == tshirts.end())
			tshirts[front[i]] = set<pair<ll, int> >();
		tshirts[front[i]].insert(mp(price[i], back[i]));
		if(tshirts.find(back[i]) == tshirts.end())
			tshirts[back[i]] = set<pair<ll, int> >();
		tshirts[back[i]].insert(mp(price[i], front[i]));
	}
	int m;
	cin >> m;
	int c;
	for(int i = 0; i < m; i++)
	{
		cin >> c;
		if(tshirts.find(c) == tshirts.end())
			cout << -1 << " ";
		else
		{
			if(tshirts[c].size() == 0)
			{
				cout << -1 << " ";
			}
			else
			{
				auto ans = *tshirts[c].begin();
				cout << ans.F << " ";
				tshirts[c].erase(ans);
				if(c != ans.S)
					tshirts[ans.S].erase(mp(ans.F, c));
			}
		}
	}
	cout << endl;
	return 0;
}