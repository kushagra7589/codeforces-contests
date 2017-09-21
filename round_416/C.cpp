#include <bits/stdc++.h>

using namespace std;

#define fast_io() ios_base::sync_with_stdio(false)

typedef long long ll;

#define mp make_pair
#define pb push_back
#define F first
#define S second

vector< pair<int, pair<int, int> > > v;

map<int, int> started;
map<int, int> ended;

std::vector<int> per;

ll calc_xor(int i)
{
	int l = v[i].F;
	int r = v[i].S.F;
	int x = i;
	ll cxor;
	ll curr = v[x].S.S;
	// cout << "Starting at : " << i << endl;
	while(x < v.size())
	{
		// int u = x;
		// cxor = 0;
		// // cout << "Segment - l = " << l;
		// while(u < v.size() && v[u].F <= r)
		// {
		// 	cxor ^= v[u].S.S;
		// 	r = max(v[u].S.F, r);
		// 	u += 1;
		// }
		// // cout << " r = " << r << endl;
		// // cout << u << endl;
		// x = u;
		// r = v[u].S.F;
		// l = v[u].F;
		// curr += cxor;
		if(v[x].F > r)
		{
			curr += v[x].S.S;
			r = v[x].S.F;
		}
		x += 1;
	}
	// cout << curr <<  endl;
	return curr;
}

int main()
{
	int n;
	cin >> n;
	per.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> per[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(started.find(per[i]) == started.end())
			started[per[i]] = i;
	}
	for(int i = n - 1; i >= 0; i--)
	{
		if(ended.find(per[i]) == ended.end())
			ended[per[i]] = i;
	}
	set<int> done;
	for(auto &i : started)
	{
		done.clear();
		int index = i.F;
		int s = i.S;
		int e = ended[i.F];
		for(int j = s; j <= e; j++)
		{
			s = min(started[per[j]], s);
			e = max(ended[per[j]], e);
		}
		index = 0;
		for(int j = s; j <= e; j++)
		{
			if(done.find(per[j]) == done.end())
			{
				done.insert(per[j]);
				index ^= per[j];
			}
		}
		v.pb(mp(s, mp(e, index)));
	}
	sort(v.begin(), v.end());
	// for(auto i : v)
	// {
	// 	cout << i.F << " " << i.S.F << " " << i.S.S << endl;
	// }
	ll max_xor = 0;
	for(int i = 0; i < v.size(); i++)
	{
		max_xor = max(max_xor, calc_xor(i));
	}
	cout << max_xor << endl;
	return 0;
}