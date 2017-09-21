#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 1e5+10;
const int INF = 1e8+10;
vector<set< int> > graph(MAX_SIZE);
int degree[MAX_SIZE] = {0};
bool visited[MAX_SIZE] = {false};
int distance1[MAX_SIZE];
long long max_color = 0;
bool in_tail[MAX_SIZE] = {false};

// void create_edge(int x, int y)
// {
// 	if(x < y)
// 		graph[x].push_back(y);
// 	degree[x] += 1;
// }

// long long bfs(int n)
// {
// 	for(int i=1; i<=n; i++)
// 	{
// 		visited[i] = false;
// 		distance1[i] = INF;
// 	}
// 	long long max_color = 0;
// 	long long color = 0;
// 	for(int i=1; i<=n; i++)
// 	{
// 		if(visited[i] == false)
// 		{
// 			// vector<int> tail;
// 			int u = i;
// 			queue<int> q1;
// 			visited[u] = true;
// 			distance1[u] = 0;
// 			q1.push(u);
// 			cout << "Starting tail at : " << u << endl;
// 			while(!q1.empty())
// 			{
// 				int s = q1.front();
// 				// tail.push_back(s);
// 				q1.pop();
// 				for(int j=0; j<graph[s].size(); ++j)
// 				{
// 					int v = graph[s][j];
// 					if(visited[v] == false)
// 					{
// 						visited[v] = true;
// 						distance1[v] = distance1[s] + 1;
// 						cout << "Ending tail at : " << v;
// 						color = (distance1[v] + 1) * degree[v];
// 						if(color > max_color)
// 							max_color = color;
// 						cout << " : Color = " << color << endl;
// 						q1.push(v);
// 					}
// 				}
// 			}
// 			// cout << i << endl;
// 			// cout << "tail : " << endl;
// 			// for(int j=1; i<tail.size(); j++)
// 			// {
// 			// 	cout << "ending at : " << tail[j] << endl;
// 			// 	color = (long long)distance1[tail[j]] * degree[tail[j]];
// 			// 	if(color > max_color)
// 			// 		max_color = color;
// 			// }
// 			// tail.clear();
// 		}
// 	}
// 	return max_color;
// }

void dfs_visit(int s, int dis)
{
	// cout << "Ending at : " << s;
	long long color = (long long)dis * degree[s];
	// cout << " : Color =  " << color << endl; 
	if(color > max_color)
		max_color = color;
	visited[s] = true;
	in_tail[s] = true;
	for(set<int>::iterator i = graph[s].begin(); i != graph[s].end(); i++)
	{
		int u = *i;
		if(visited[u] == false)
		{
			dfs_visit(u, dis + 1);
		}
	}
}


void dfs(int n)
{
	for(int i=1; i<=n; i++)
	{
		if(in_tail[i] == false)
		{
			// visited[i] = true;
			// cout << "Starting at :  " << i << endl;
			for(int j=i+1; j<=n; j++)
				visited[j] = false;
			dfs_visit(i, 1);
		}
	}
}
void display_graph(int n)
{
	for(int i=1; i<=n; i++)
	{
		cout << "degree[" << i<<"] = " << degree[i] << endl;
		cout << i ;
		for(set<int>::iterator j = graph[i].begin(); j != graph[i].end(); j++)
		{
			cout << "->" << *j;	
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int x, y;
	for(int i=0; i<m; i++)	
	{
		cin >> x >> y;
		degree[x] += 1;
		degree[y] += 1;
		graph[min(x, y)].insert(max(x, y));
	}
	// display_graph(n);
	dfs(n);
	cout << max_color << endl;
	return 0;
}