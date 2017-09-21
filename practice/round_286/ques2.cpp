#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_SIZE = 102;

vector< vector<pair<int, int> > > graph(MAX_SIZE);
vector< int > color_edge (MAX_SIZE, 0);
vector< int > temporary = color_edge;
vector< vector<bool > > visited(MAX_SIZE, vector<bool>(MAX_SIZE, false));
vector< vector<bool > > temp = visited;
vector< set<int> > color_node(MAX_SIZE);

void bfs(int x, set<int> c)
{
	queue<int> q;
	q.push(x);
	while(!q.empty())
	{
		int node = q.front();
		q.pop();
		for(int i=0; i<graph[node].size(); i++)
		{
			int u = graph[node][i].first;
			int color = graph[node][i].second;
			if(color.edge)
			if(c.find(color) != c.end() && visited[u][color] == false)
			{
				color_edge[u] += 1;
				visited[u][color] = true;
				q.push(u);
			}
		}
	} 
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int x, y, c;
	for(int i=0; i<m; i++)
	{
		cin >> x >> y >> c;
		graph[x].push_back(make_pair(y, c));
		graph[y].push_back(make_pair(x, c));
		color_node[x].insert(c);
		color_node[y].insert(c);
	}
	int q;
	cin >> q;
	while(q--)
	{
		cin >> x >> y;
		for(set<int>::iterator i = color_node[x].begin(); i != color_node[x].end(); i++)
		{
			visited[x][*i] = true;
		}
		bfs(x, color_node[x]);
		cout << color_edge[y] << endl;
		color_edge = temporary;
		visited = temp;
	}
	return 0;
}