#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define F first
#define S second

vector<string> grid; 
int main()
{
	freopen ("class.in","r+",stdin);
	freopen ("class.out","w+",stdout);
	ios_base::sync_with_stdio(false);
	int n, r, c;
	cin >> n >> r >> c;
	for(int i = 0; i < r; i++)
	{
		string a(c, '.');
		grid.pb(a);
	}
	int M = min(r, c);
	if(n >= 2*M - 1)
	{
		grid[0][0] = '#';
		for(int i = 1; i < M; i++)
		{
			grid[0][i] = '#';
			grid[i][0] = '#';
		}
		int count1 = 2*M - 1;
		bool done = false;
		for(int i = 1; i < r; i++)
		{
			for(int j = 1; j < c; j++)
			{
				if(count1 >= n)
				{
					done = true;
					break;
				}
				grid[i][j] = '#';
				count1++;
			}
			if(done)
				break;
		}
		if(!done)
		{
			if(r <= c)
			{
				for(int i = M; i < c; i++)
				{
					if(count1 >= n)
						break;
					grid[0][i] = '#';
					count1++;
				}
			}
			else
			{
				for(int i = M; i < r; i++)
				{
					if(count1 >= n)
						break;
					grid[i][0] = '#';
					count1++;
				}
			}
		}
		cout << M << endl;
	}
	else
	{
		grid[0][0] = '#';
		int ans = (n - 1)/2 + 1;
		cout << ans << endl;
		for(int i = 1; i <= (n-1)/2; i++)
		{
			grid[0][i] = '#';
		}
		for(int i = 1; i <= (n-1) - (n-1)/2; i++)
		{
			grid[i][0] = '#';
		}
	}
	for(auto &i: grid)
	{
		cout << i << endl;
	}
	return 0;
}