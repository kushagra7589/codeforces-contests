#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

set<pair<pll, pll > > points;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string input;
	cin >> input;
	int x = 0;
	int y = 0;
	int ans = 0;
	pll curr;
	curr = mp(0, 0);
	for(auto it : input)
	{
		cout << "Current state:  " << endl;
		// for(auto k : points)
		// {
		// 	cout << k.F.F << " " << k.F.S << "  " << k.S.F << " " << k.S.S << endl;
		cout << curr.F << " " <<  curr.S << endl;
		// }
		if(it == 'R')
		{
			x += 1;
			if(points.find(mp(mp(curr.F, curr.S), mp(curr.F + 1, curr.S))) == points.end())
			{
				points.insert(mp(mp(curr.F, curr.S), mp(curr.F + 1, curr.S)));
			}
			else
			{
				ans += 2;		
				points.erase(mp(mp(curr.F, curr.S), mp(curr.F + 1, curr.S)));
			}
			curr.F += 1;
		}
		else if(it == 'L')
		{
			x -= 1;
			if(points.find(mp(mp(curr.F-1, curr.S), mp(curr.F, curr.S))) == points.end())
			{
				points.insert(mp(mp(curr.F-1, curr.S), mp(curr.F, curr.S)));
			}
			else
			{
				ans += 2;
				points.erase(mp(mp(curr.F-1, curr.S), mp(curr.F, curr.S)));
			}
			curr.F -= 1;
		}
		else if(it == 'U')
		{
			y += 1;
			if(points.find(mp(mp(curr.F, curr.S), mp(curr.F, curr.S+1))) == points.end())
			{
				points.insert(mp(mp(curr.F, curr.S), mp(curr.F, curr.S+1)));
			}
			else
			{
				ans += 2;
				points.erase(mp(mp(curr.F, curr.S), mp(curr.F , curr.S+1)));
			}
			curr.S += 1;
		}
		else if(it == 'D')
		{
			y -= 1;
			if(points.find(mp(mp(curr.F, curr.S-1), mp(curr.F, curr.S))) == points.end())
			{
				points.insert(mp(mp(curr.F, curr.S-1), mp(curr.F, curr.S)));
			}
			else
			{
				ans += 2;
				points.erase(mp(mp(curr.F, curr.S-1), mp(curr.F, curr.S)));
			}
			curr.S -= 1;
		}
	}

	cout << abs(x) << " " << abs(y) << endl;
	ans += abs(x) + abs(y);
	cout << ans << endl;
	return 0;
}