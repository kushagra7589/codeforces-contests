#include <bits/stdc++.h>

using namespace std;

int make_edge(int x, int y) 
{ 
	graph[x].push_back(y);
}

int dfs_visit(int x) {
	visited[x] = true;
	int k;
	for(int i=0; i<=graph[x].size(); i++) {
		if(visited[i] == false)
			k = dfs_visit(i);
		grd
	}
}

int dfs(int n)
{
	for(int i=n; n>=1; i--) {
		if(visited[i] == false)
			dfs_visit(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	return 0;
}