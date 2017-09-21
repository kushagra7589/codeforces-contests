#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 150010;

#define ll long long
#define pb push_back

vector< int > graph[MAX_SIZE];
bool visited[MAX_SIZE];

vector<int> conn;
int degree[MAX_SIZE] = {0};

void dfs(int x)
{
	visited[x] = true;
	conn.pb(x);
	for(auto &i : graph[x])
	{
		if(!visited[i])
		{
			dfs(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int x, y;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		graph[x].pb(y);
		graph[y].pb(x);
		degree[x]++;
		degree[y]++;
	}
	for(int i = 0; i <= n; i++)
		visited[i] = false;

	for(int i = 1; i <= n; i++)
	{
		if(!visited[i])
		{
			conn.clear();
			dfs(i);
			int N = conn.size();
			for(int j = 0; j < N; j++)
			{
				if(degree[conn[j]] != N - 1)
				{
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}