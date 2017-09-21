#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 2e5+10;

int arr[MAX_SIZE];
bool visited[MAX_SIZE] = {false};

vector<vector<int> > graph(MAX_SIZE, vector<int>());

void create_edge(int x, int y)
{
	graph[x].pb(y);
}

void dfs(int x)
{
	visited[x] = true;
	for(auto it : graph[x])
	{
		if(visited[it] == false)
		{
			dfs(it);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
		create_edge(i, arr[i]);
	}
	int ones = 0;
	int b;
	for(int i=1; i<=n; i++)
	{
		cin >> b;
		ones += b;
	}
	for(int i=1; i<=n; i++)
	{
		visited[i] = false;
	}
	int cycles =0;
	for(int i=1; i<=n; i++)
	{
		if(visited[i] == false)
		{
			// cout << i << endl;
			cycles += 1;
			dfs(i);
		}
	}
	int change = 0;
	if(cycles == 1)
		change = (ones+1) % 2;
	else
		change = cycles + ((ones+1) % 2);
	cout << change << endl;
	return 0;
}