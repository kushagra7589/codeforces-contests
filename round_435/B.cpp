#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define F first
#define S second

const int MAX_SIZE = 1e5 + 10;

vector<int> graph[MAX_SIZE];
bool visited[MAX_SIZE];
int color[MAX_SIZE];
ll cnt[2];

void bfs(int s, int n)
{
	for(int i = 1; i <= n; i++)
	{
		color[i] = -1;
		visited[i] = false;
	}
	visited[s] = true;
	color[s] = 1;
	cnt[1] += 1;
	queue<int> q;
	q.push(s);
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(auto &v: graph[u])
		{
			if(!visited[v])
			{
				color[v] = 1 - color[u];
				cnt[1 - color[u]] += 1;
				visited[v] = true;
				q.push(v);
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int a, b;
	for(int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	bfs(1, n);
	ll ans = 0;
	// cout << cnt[0] << " " << cnt[1] << endl << endl;
	for(int i = 1; i <= n; i++)
	{
		// cout << i << " : " << graph[i].size() << " " << color[i] << endl;
		ans += cnt[1 - color[i]]  - graph[i].size();
	}
	cout << ans / 2 << endl;
	return 0;
}