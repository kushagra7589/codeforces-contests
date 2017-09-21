#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string input;
	cin >> input;
	char x = 'X';
	char y = 'X';
	int ans=1;
	for(auto it : input)
	{
		if(it == 'R')
		{
			if(x == 'L')
			{
				ans += 1;
				y = 'X';
			}
			x = 'R';
		}
		else if(it == 'L')
		{
			if(x == 'R')
			{
				ans += 1;
				y = 'X';
			}
			x = 'L';
		}
		else if(it == 'U')
		{
			if(y == 'D')
			{
				ans += 1;
				x = 'X';
			}
			y = 'U';
		}
		else
		{
			if(y == 'U')
			{
				ans += 1;;
				x = 'X';
			}
			y = 'D';
		}
	}
	cout << ans << endl;
	return 0;
}