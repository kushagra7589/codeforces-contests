#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_SIZE = 5e3 + 10;

ll a[MAX_SIZE];
ll prefix[MAX_SIZE];

ll dp[MAX_SIZE][MAX_SIZE] = {0};
bool flag[MAX_SIZE];

int start[MAX_SIZE] = {0};
int end[MAX_SIZE];

int n;
ll solve(int i, int last)
{
	if(i == n+1)
		return 0;
	if(flag[a[i]])
		return solve(i + 1, last);
	flag[a[i]] = true;
	if(dp[i][last] == -1)
	{
		if(start[a[i]] >= last)
		{
			dp[i][last] = solve(i + 1, last);
		}
		else
		{
			dp[i][last] = max((prefix[end[a[i]]]^prefix[start[a[i]] - 1]) + solve(i + 1, end[a[i]]), solve(i + 1, last));
		}
	}
	return dp[i][last];
}

int main()
{
	cin >> n;
	prefix[0] = 0;
	for(int i = 1; i <= 5000; i++)
		flag[i] = false;

	for(int i = 0; i < MAX_SIZE; i++)
	{
		for(int j = 0; j < MAX_SIZE; j++)
			dp[i][j] = -1;
	}
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		// prefix[i] = prefix[i - 1]^a[i];
	}
	for(int i = 1; i <= n; i++)
	{
		if(start[a[i]] == 0)
		{
			start[a[i]] = i;
		}
		end[a[i]] = i;
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = start[a[i]]; j <= end[a[i]]; j++)
		{
			start[a[i]] = min(start[a[i]], start[a[j]]);
			end[a[i]] = max(end[a[i]], end[a[j]]);
		}
	}
	for(int i = 1; i <= 5000; i++)
	{
		if(start[a[i]] != 0)
		{
			int l = start[a[i]], r = end[a[i]];
			for(int j = l; j <= r; i++)
			{
				
			}
		}
	}
	for(int i = 1; i <= n; i++)
	{
		cout << a[i] << " : " << start[a[i]] << " " << end[a[i]] << endl;
	}
	ll ans = solve(1, 0);
	cout << ans << endl;
	return 0;
}