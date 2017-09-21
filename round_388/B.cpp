#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pll pair<ll, ll>
#define mp make_pair
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	vector< pll > crd;
	crd.resize(3);
	int x, y;
	for(int i=0; i<3; i++)
	{
		cin >> x >> y;
		crd[i] = mp(x, y);
	}	
	// for(auto it : crd)
	// {
	// 	cout << it.F << " " << it.S << endl;
	// }
	set<pll> ans;
	ans.insert(mp(crd[0].F + (crd[1].F - crd[2].F), crd[0].S + (crd[1].S - crd[2].S)));
	ans.insert(mp(crd[0].F - (crd[1].F - crd[2].F), crd[0].S - (crd[1].S - crd[2].S)));
	ans.insert(mp(crd[1].F + (crd[0].F - crd[2].F), crd[1].S + (crd[0].S - crd[2].S)));
	ans.insert(mp(crd[1].F - (crd[0].F - crd[2].F), crd[1].S - (crd[0].S - crd[2].S)));
	ans.insert(mp(crd[2].F - (crd[0].F - crd[1].F), crd[2].S - (crd[0].S - crd[1].S)));
	ans.insert(mp(crd[2].F + (crd[0].F - crd[1].F), crd[2].S + (crd[0].S - crd[1].S)));
	// ans.insert(mp(crd[0].F + (crd[1].F - crd[2].F), crd[0].S - (crd[1].S - crd[2].S)));
	// ans.insert(mp(crd[0].F + (crd[1].F - crd[2].F), crd[0].S - (crd[1].S - crd[2].S)));
	// ans.insert(mp(crd[1].F + (crd[0].F - crd[2].F), crd[1].S - (crd[0].S - crd[2].S)));
	// ans.insert(mp(crd[1].F - (crd[0].F - crd[2].F), crd[1].S + (crd[0].S - crd[2].S)));
	// ans.insert(mp(crd[2].F + (crd[0].F - crd[1].F), crd[2].S - (crd[0].S - crd[1].S)));
	// ans.insert(mp(crd[2].F - (crd[0].F - crd[1].F), crd[2].S + (crd[0].S - crd[1].S)));

	cout << ans.size() << endl;
	for(auto it : ans)
	{
		cout << it.F << " " << it.S << endl;
	}
	return 0;
}