#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll K[1010];
vector< ll > A;

ll cnt = 0;

vector< ll > adj[1010];
bool visited[1010];

void create_edge(int x, ll y)
{
	adj[x].push_back(y);
	adj[y].push_back(x);
}

ll nc2(ll n)
{
	if(n < 2)
		return 0;
	else
	{
		return (n*(n-1))/2;
	}
}

void bfs(int u)
{
	queue< int > q1;
	q1.push(u);
	while(!q1.empty())
	{
		int x  = q1.front();
		q1.pop();
		cnt += 1;
		visited[x] = true;
		for(auto it : adj[x])
		{
			if(!visited[it])
			{
				q1.push(it);
			}
		}
	}
}

int main()
{
	ll n, m, k;
	cin >> n >> m >> k;
	for(int i=0; i<k; i++)
	{
		cin >> K[i];
	}

	ll x, y;
	for(int i=0; i<m; i++)
	{
		cin >> x >> y;
		create_edge(x, y);
	}

	int max_count = 0;
	for(int i=0; i<k; i++)
	{
		cnt  = 0;
		bfs(K[i]);
		A.push_back(cnt);
		if(A[max_count] < A[i])
			max_count = i;
	}

	ll sum = 0;
	for(int i=0; i<k; i++)
	{
		sum += A[i];
	}
	A[max_count] += n - sum;

	ll ans = 0;

	for(int i=0; i<k; i++)
	{
		ans += nc2(A[i]);
	}
	cout << ans - m << endl;
}