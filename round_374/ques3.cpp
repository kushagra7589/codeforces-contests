#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 5e3+10;

vector< unordered_map<int, ll > > graph(MAX_SIZE); 

void create_edge(int x, int y, ll t)
{
	graph[x][y] = t;
}

void dfs(int current, int dest, vector<bool> &visited, vi &path, int &index, int T, vi &max_path, int &max_index, ll &max_time)
{
	visited[current] = true;
	path[index] = current;
	index += 1;
	if(current == dest)
	{
		ll sum = 0;
		for(int i=0; i<index-1; i++)
		{
			sum += graph[path[i]][path[i+1]];	
		}
		if(sum <= T)
		{
			if(index > max_index)
			{
				max_time = sum;
				max_path = path;
				max_index = index;
			}
		}
	}
	else
	{
		for(auto i : graph[current])
		{
			if(visited[i.F] == false)
				dfs(i.F, dest, visited, path, index, T, max_path, max_index, max_time);
		}
	}
	visited[current] = false;
	index -= 1;
}

void dfs_visit(int s, int d, ll T)
{
	vector<bool> visited(MAX_SIZE);
	for(int i=0; i<MAX_SIZE; i++)
		visited[i] = false;
	vector<int> path(MAX_SIZE);
	vll all_times;
	int index = 0;
	vi max_path;
	int max_index = 0;
	ll max_time = 0;
	dfs(s, d, visited, path, index, T, max_path, max_index, max_time);
	cout << max_index << endl; 
	for(int i = 0; i< max_index; i++)
	{
		cout << max_path[i] << " ";
	}
	cout << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	int n, m; ll T;
	cin >> n >> m >> T;
	int x, y; ll t;
	for(int i=0; i<m; i++)
	{
		cin >> x >> y >> t;
		create_edge(x, y, t);
	}
	dfs_visit(1, n, T);
	return 0;
}