#include <bits/stdc++.h>

using namespace std;

#define fast_io() ios_base::sync_with_stdio(false);
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pll pair<ll, ll>

typedef long long ll;

vector<string> floors;
set<ll> sums[16];
int first[16];
int last[16];
int n, m;

int get_node(int i, int j)
{

}

vector< pair<int, ll > > graph[int(1e4)];
// int dp(int f, int room)
// {
// 	cout << f << " " << room << endl;
// 	if(f == last && sums[f].size() == 0)
// 	{
// 			return 0;
// 	}
// 	if(sums[f].size() == 0)
// 	{
// 		if(room == 0 || room == m + 1)
// 		{
// 			return 1 + dp(f - 1, room);
// 		}
// 		else
// 		{
// 			return min(room + dp(f, 0), abs(m + 1 - room) + dp(f, m + 1));
// 		}
// 	}
// 	int first = *sums[f].begin();
// 	auto fi = sums[f].end();
// 	fi--;
// 	int finish = *fi;
// 	cout << "s = "  << first << " f = " << finish << endl;
// 	if(abs(first - room) <= abs(finish - room))
// 	{
// 		sums[f].erase(first);
// 		return abs(first - room) + dp(f, first);
// 	}
// 	else
// 	{
// 		sums[f].erase(finish);
// 		return abs(finish - room) + dp(f, finish);
// 	}
// }
const int INF = 1e8;
vector<ll> dist(int(1e4), INF);

void shortestPath(int src)
{
	priority_queue< pll, vector< pll >, greater< pll > > pq;
	pq.push(mp(0, src));
	dist[src] = 0;

	while(!pq.empty())
	{
		int u = pq.top().S;
		pq.pop();

		for(auto it : graph[u])
		{
			int v = it.F;
			ll weight = it.S;

			if(dist[v] > dist[u] + weight)
			{
				dist[v] = dist[u] + weight;
				pq.push(mp(dist[v], v));
			}
		}
	}


}

int main()
{
	fast_io();
	cin >> n >> m;
	floors.resize(n);
	for(int i = 0; i < n; i++)
	{
		first[i] = 0;
		last[i] = 0;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> floors[i];
		for(int j = 1; j <= m; j++)
		{
			if(floors[i][j] == '1')
			{
				if(first[i] == 0)
					first[i] = j;
				last[i] = j;
			}
		}
	}
	int k = 0;
	while(last[k] == 0)
	{
		k++;
	}

	for(int i = 0; i < n; i++)
	{
		graph[n*m + 1 + i*4].pb(mp(i*m + last[i], last[i] - 0));
		graph[n*m + 1 + i*4 + 1].pb(mp(i*m + first[i], first[i] - 0));
		graph[n*m + 1 + i*4 + 1].pb(mp(i*m + last[i], last[i] - 0));
		graph[n*m + 1 + i*4 + 2].pb(mp(i*m + first[i], m + 1 - first[i]));
		graph[n*m + 1 + i*4 + 3].pb(mp(i*m + first[i], m + 1 - first[i]));
		graph[n*m + 1 + i*4 + 3].pb(mp(i*m + last[i], m + 1 - first[i]));		
		graph[i*m + 1 + first[i]].pb(mp(i*m + last[i], last[i] - first[i]));
		graph[i*m + 1 + last[i]].pb(mp(i*m + first[i], last[i] - first[i]));
		graph[i*m + 1 + i*4].pb(mp((i+1)*4 + 1 + n*m))
	}
	// cout << " last = " << last << endl;
	// while(sums[last].size() == 0)
	// 	last += 1;
	// cout << dp(n - 1, 0) << endl;
	shortestPath(n*m + 1);
	cout << min(dist[first[k]], dist[last[k]]) << endl;;
	return 0;
}