#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	ll n, x;
	cin >> n >> x;
	ll curr = x;
	string type;
	int dis = 0;
	ll amt;
	for(int i=0; i<n; i++)
	{
		cin >> type >> amt;
		if(type == "+")
		{
			curr += amt;
		}
		else if(type == "-")
		{
			if(curr >= amt)
			{
				curr -= amt;
			}
			else
			{
				dis += 1;
			}
		}
	}
	cout << curr << " " << dis << endl;
	return 0;
}