#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define F first
#define S second

const int MAX_SIZE = 1e5+10;
const int M = 1e9+7;

ll dp[MAX_SIZE] = {0};

vector<vi > graph(MAX_SIZE);
ll degree[MAX_SIZE] = {0};

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int x, y;
	for(int i=0; i<m; i++)
	{
		cin >> x >> y;
		if(x > y)
			graph[x].pb(y);
		else
			graph[y].pb(x);
		degree[x] += 1;
		degree[y] += 1;
	}
	for(int i=1; i<=n; i++)
	{
		dp[i] = 1;
		for(int j=0; j<graph[i].size(); j++)
		{
			dp[i] = max(dp[i], dp[graph[i][j]] + 1);
		}
	}
	ll res = 0;
	for(int i=1; i<=n; i++)
	{
		res = max(res, dp[i]*degree[i]);
	}
	cout << res << endl;
	return 0;
}