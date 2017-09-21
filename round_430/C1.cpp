#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;

const int MAX_SIZE = 2e5 + 10;

vector<int> graph[MAX_SIZE];
int value[MAX_SIZE];
bool visited[MAX_SIZE] = {0};
int dp[MAX_SIZE][3];

int gcd1(int a, int b)
{
	if(b == 0) return a;
	if(a < b) return gcd1(b, a);
	return gcd1(b, a % b);
}

void dfs(int a)
{
	visited[a] = true;
	for(auto &v : graph[a])
	{
		if(!visited[v])
		{
			// cout << "v = " << v << " " << "value = " << value[v] << " " << gcd1(value[v], dp[a][0]) << " " << gcd1(value[v], dp[a][1]) << " " << dp[a][1] << endl;
			dp[v][0] = max(gcd1(value[v], dp[a][0]), gcd1(value[v], dp[a][2]));
			dp[v][1] = gcd1(value[v], dp[a][1]);
			dp[v][2] = dp[a][1];
			dfs(v);
		}
	}
}


int main()
{
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> value[i];
	}
	int x, y;
	for(int i = 1; i < n; i++)
	{
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
	}
	dp[1][0] = value[1];
	dp[1][1] = value[1];
	dp[1][2] = 0;
	dfs(1);
	for(int i = 1; i <= n; i++)
	{
		cout << max(max(dp[i][0], dp[i][1]), dp[i][2]) << " ";
	}
	cout << endl;
	return 0;
}