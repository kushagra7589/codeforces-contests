#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

const int N = 3e5 + 10;
const int MAX_LOG = log(N) + 1;
int d[N];
set<int> A, B;

vector< pair<int, int> > graph[N];
const int max_nodes, log_max_nodes;
int num_nodes, log_num_nodes, root;

vector<int> children[max_nodes];	// children[i] contains the children of node i
int A[max_nodes][log_max_nodes+1];	// A[i][j] is the 2^j-th ancestor of node i, or -1 if that ancestor does not exist
int L[max_nodes];			// L[i] is the distance between node i and the root

// floor of the binary logarithm of n
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

int main(int argc,char* argv[])
{
    // read num_nodes, the total number of nodes
    ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
    log_num_nodes=lb(n);
    for(int i = 1; i <= n; i++) {
		cin >> d[i];
	}
    for(int i = 0; i < num_nodes; i++)
    {
	int p;
	// read p, the parent of node i or -1 if node i is the root
	A[i][0] = p;
	if(p != -1)
	    children[p].push_back(i);
	else
	    root = i;
    }
    // precompute A using dynamic programming
    for(int j = 1; j <= log_num_nodes; j++)
	for(int i = 0; i < num_nodes; i++)
	    if(A[i][j-1] != -1)
		A[i][j] = A[A[i][j-1]][j-1];
	    else
		A[i][j] = -1;
    // precompute L
    DFS(root, 0);   
    return 0;
}
int main() {
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> d[i];
		if(d[i] == 1) 
			A.insert(i);
		else if(d[i] == -1) 
			B.insert(i);
	}	
	int x, y;
	for(int i = 1; i <= m; i++) {
		cin >> x >> y;
		graph[x].pb({y, i});
		graph[y].pb({x, i});
	}
	vector<int> ans;
	for(auto &b: B) {
		for(auto &i : graph[b]) {
			if(d[i.F] == 1) {
				ans.pb(i.S);
				d[i.F] = 0;
				A.erase(i.F);
			}
		}
	}
	for(auto &a : A) {
		for(auto &i : graph[a]) {
			if(d[i.F] == 1) {
				ans.pb(i.S);
				d[i.F] = 0;
				d[a] = 0;
			}
		}
	}
	set<int> one1;
	for(auto &a: A) {
		if(d[a] == 1)
			one1.insert(a);
	}
	one.clear();
	if(one1.size() % 2) {
		cout << -1 << endl;
		return 0;
	}
	for()
	return 0;
}