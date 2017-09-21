#include <bits/stdc++.h>

using namespace std;

#define F first 
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>

map<string, set<int, greater<int> > > beauty;

int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> k >> n;
	string input;
	int b;
	for(int i=0; i<k; i++)
	{
		cin >> input >> b; 
		if(beauty.find(input) == beauty.end())
		{
			set<int, greater<int> > temp;
			beauty[input] = temp;
		}
		beauty[input].insert(b);
	}
	ll ans = 0;
	vector< pii > max_self;
	for(auto it : beauty)
	{
		string rev = it.F;
		reverse(rev.begin(), rev.end());
		if(it.F != rev)
		{
			if(beauty.find(rev) != beauty.end())
			{	
				if(it.S.size() > 0 && beauty[rev].size() > 0)
				{
					auto b = it.S.begin();
					auto bpalin = beauty[rev].begin();

					while(*b + *bpalin > 0)
					{
						ans += *b + *bpalin;
						// cout << "adding " << it.F << " and " << rev << endl;
						it.S.erase(b);
						beauty[rev].erase(bpalin);
						if(it.S.size() > 0 && beauty[rev].size() > 0)
						{
							b = it.S.begin();
							bpalin = beauty[rev].begin();
						}
						else
						{
							break;
						}
					}
				}
			}
		}
		else
		{
			auto b = it.S.begin();
			auto bpalin = b; bpalin++;
			while(bpalin != it.S.end() && (*b + *bpalin > *b))
			{
				ans += (*b + *bpalin);
				it.S.erase(b);
				it.S.erase(bpalin);
				if(it.S.size() > 0)
				{
					b = it.S.begin();
					bpalin = b; bpalin++;
				}
			}
			if(it.S.size() > 1)
			{
				max_self.pb(mp(*b, max(0, *b + *bpalin)));
			}
			else
			{
				max_self.pb(mp(*b, 0));
			}
		}
	}
	int total = 0;
	for(auto it : max_self)
	{
		// cout << it.S << " " << it.F << endl;
		total += it.S;
	}
	int add = 0;
	for(auto it : max_self)
	{
		add = max(add, total - it.S + it.F);
	}
	// cout << add << endl;
	ans += add;
	cout << ans << endl;
}