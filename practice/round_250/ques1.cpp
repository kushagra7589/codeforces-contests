#include <bits/stdc++.h>

using namespace std;

#define vsi vector<set < int> >
#define pb push_back
#define I insert
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 1e5+10;

// vsi graph(MAX_SIZE, set<int> 0);
vector< pair< int,  int > > edges;
vector<int> parent(MAX_SIZE);
vector<int> union_size(MAX_SIZE, 0);
vector< pair<int, int> > weight;
vector< vector<int> > children(MAX_SIZE, vector<int>());

void initialise(int n)
{
	for(int i=1; i<=n; i++)
	{
		parent[i] = i;
		union_size[i] = 1;
	}
}

int find_root(int i)
{
	while(parent[i] != i)
	{
		i = parent[i];
	}
	return i;
}

bool check(int a, int b)
{
	return find_root(a) == find_root(b); 
}

void makeRoot(int a, int b)
{
	while()
}

void unison(int b)
{
	if(!check(a, b))
	{
		int root_a = find_root(a);
		int root_b = find_root(b);
		if(union_size[root_a] < union_size[root_b])
		{
			parent[root_a] = root_b;
			union_size[root_b] += union_size[root_a];
			// children[root_b].pb(root_a);
			// union_size[root_a] = 0;
		}
		else
		{
			parent[root_b] = root_a;
			union_size[root_a] += union_size[root_b];
			children[root_a].pb(root_b);
		}
	}
}

void delete(int a)
{
	for(auto i : graph[a])
	{
		parent[i] = i;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int temp;
	for(int i = 0; i<n; i++)
	{
		cin >> temp;
		weight.pb(mp(temp, i));
	}
	sort(weight.begin(), weight.end());
	int x, y;
	while(m--)
	{
		cin >> x >> y;
		edges.pb(mp(x, y));
		edges.pb(mp(y, x));
	}
	initialise(n);
	for(auto i : edges)
	{
		unison(i.F, i.S);
	}
	long double ans = 0;
	for(auto i : weight)
	{
		ans += (ll)i.F*union_size[i.S];
		delete(i.S);
	}
}