#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

vector<pll> input;
vector<pair<ll, bool> > start;

int Search(int l, int u, ll s)
{
	while(l <= u)
	{
		int mid = (l + u)/2;
		if(start[mid] == s)
		{

			return mid;
		}
		else if(start[mid] < s)
		{
			l = mid + 1;
		}
		else
			u = mid - 1;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	input.resize(n);
	// start.resize(n);
	for(int i=0; i<n; i++)
	{
		cin >> input[i].F;
		cin >> input[i].S;
		start.pb(mp(input[i].F, true));
		start.pb(mp(input[i].F + input[i].S - 1, true));
	}
	sort(start.begin(), start.end());
	for(auto i : input)
	{
		int x = 
	}
}