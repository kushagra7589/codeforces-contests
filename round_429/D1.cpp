#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

const int N = 3e5 + 10;
int log_num_nodes, root;

int A[N][(int)log(N)+2];	// A[i][j] is the 2^j-th ancestor of node i, or -1 if that ancestor does not exist
int L[N];

int lb(unsigned int n)
{
    if(n==0)
	return -1;
    int p = 0;
    if (n >= 1<<16) { n >>= 16; p += 16; }
    if (n >= 1<< 8) { n >>=  8; p +=  8; }
    if (n >= 1<< 4) { n >>=  4; p +=  4; }
    if (n >= 1<< 2) { n >>=  2; p +=  2; }
    if (n >= 1<< 1) {           p +=  1; }
    return p;
}
int d[N];
// int one[N];
vector<int > one;
vector<int> minus;
vector<pair<int, int> > graph[N];
vector<int> children[N];
vector<bool> visited(N, false);
vector<pair<int, int> > parent(N, -1);

int dfs(int s) {
	visited[s] = true;
	for(auto &e: graph[s]) {
		if(!visited[e.F]) {
			parent[e.F] = {s, e.S}; 
			dfs(e.F);
		}
	}
}

void DFS(int i, int l)
{
    L[i] = l;
    for(int j = 0; j < children[i].size(); j++)
	DFS(children[i][j], l+1);
}

int LCA(int p, int q)
{
    // ensure node p is at least as deep as node q
    if(L[p] < L[q])
	swap(p, q);
    // "binary search" for the ancestor of node p situated on the same level as q
    for(int i = log_num_nodes; i >= 0; i--)
	if(L[p] - (1<<i) >= L[q])
	    p = A[p][i];
    if(p == q)
	return p;
    // "binary search" for the LCA
    for(int i = log_num_nodes; i >= 0; i--)
	if(A[p][i] != -1 && A[p][i] != A[q][i])
	{
	    p = A[p][i];
	    q = A[q][i];
	}
    return A[p][0];
}

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> d[i + 1];
		if(d[i + 1] == 1)
			one.pb(i + 1);
		else if(d[i + 1] == -1) {
			minus.pb(i + 1);
		}
	}
	int x, y;
	for(int i = 1; i <= m; i++) {
		cin >> x >> y;
		graph[x].pb({y, i});
		graph[y].pb({x, i});
	}
	dfs(1);
	log_num_nodes=lb(n);
	for(int i = 1; i <= n; i++)
    {
	// int p;
	// // read p, the parent of node i or -1 if node i is the root
	A[i][0] = parent[i];
	if(p != -1)
	    children[p].push_back(i);
	else
	    root = i;
    }
    for(int j = 1; j <= log_num_nodes; j++)
		for(int i = 0; i < n; i++)
		    if(A[i][j-1] != -1)
				A[i][j] = A[A[i][j-1]][j-1];
		    else
				A[i][j] = -1;
	DFS(root, 0);
	vector<int> ans;
	for(int i = 0; i < one.size() - 1; i+=2) {
		int p = LCA(one[i], one[i + 1]);
		int temp = one[i];
		while(temp != p) { 
			ans.pb(parent[temp].S);
			temp = parent[temp].F;
		}
		temp = one[i + 1];
		while(temp != p) { 
			ans.pb(parent[temp].S);
			temp = parent[temp].F;
		}
		d[i] = 0;
		d[i + 1] = 0;
	}
	if(d[one[one.size() - 1]] == 1) {
		if(minus.size() == 0) {
			cout << -1 << endl;
			return 0;
		}
		int p = LCA(one[one.size() - 1], minus[0]);
		int temp = one[one.size() - 1];
		while(temp != p) { 
			ans.pb(parent[temp].S);
			temp = parent[temp].F;
		}
		// temp = one[i + 1];
		while(temp != p) { 
			ans.pb(parent[temp].S);
			temp = parent[temp].F;
		}
	}
	cout << ans.size() << endl;
	for(auto &a : ans) {
		cout << a << " ";
	}
	return 0;
	return 0;
}