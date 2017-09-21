#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 1e5+10;

set<string> U;
set<string> V;
set<string> ans;
unordered_map<string, vector<string> > graph;
unordered_map<string, bool > visited;


void bfs()
{
	queue<string> q1;
	for(auto i : U)
	{
		if(visited.find(i) == visited.end())
		{
			visited[i] = true;
			q1.push(i);
		}
		while(!q1.empty())
		{
			auto x = q1.front();
			q1.pop();
			if(V.find(x) != V.end())
				ans.insert(x);
			for(auto u : graph[x])
			{
				if(visited.find(u) == visited.end())
				{
					visited[u] = true;
					q1.push(u);
				}
			}
		}
	}
}

void display()
{
	for(auto i = graph.begin(); i != graph.end(); i++)
	{
		cout << i->first ;
		for(auto j = i->second.begin(); j != i->second.end(); j++)
		{
			cout << "->" << *j;
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int u, v, m;
		cin >> u >> v >> m;
		string name;
		for(int i=0; i<u; i++)
		{
			cin >> name;
			U.insert(name);
		}
		for(int i=0; i<v; i++)
		{
			cin >> name;
			V.insert(name);
		}
		string a, b;
		while(m--)
		{
			cin >> a >> b;
			graph[a].pb(b);
		}
		bfs();
		for(auto i : ans)
		{
			cout << i << " ";
		}
		cout << endl;
		U.clear();
		V.clear();
		graph.clear();
		visited.clear();
		ans.clear();
	}
	return 0;
}