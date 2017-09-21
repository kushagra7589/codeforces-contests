#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 1e5+10;

vector< vector<int> > graph(MAX_SIZE, vector<int>());
vector< pair<int, int> > weight;
vector< int > union_size(MAX_SIZE, 0);
vector< int > parent(MAX_SIZE);
// vector< int > w(MAX_SIZE);
vector< bool > visited(MAX_SIZE, false);

void create_edge(int x, int y)
{
	graph[x].pb(y);
}

void initialise(int n)
{
	for(int i=0; i<=n; i++)
	{
		parent[i] = i;
		union_size[i] = 0;
	}
}

int findRoot(int x)
{
	while(parent[x] != x)
	{
		x = parent[x];
	}
	return x;
}

void unison(int a, int b)
{
	int i = b;
	parent[b] = a;
	union_size[a] += 1;
	while(visited[i] == false)
	{
		union_size[parent[i]] += (union_size[i]);
		i = parent[i];
	}
	union_size[parent[i]] += union_size[i];
}

void delete1(int a)
{
	if(parent[a] == a)
	{
		for(auto i : graph[a])
		{
			parent[i] = i;
		}
	}
	else
	{
		int rootA = findRoot(a);
		union_size[rootA] -= union_size[a];
		parent[a] = a; 
	}
}

void display(int n)
{
	for(int i=1; i<=n; i++)
	{
		int u = i;
		cout << u;
		while(parent[u] != u)
		{
			cout << "->" << parent[u];
			u  = parent[u];
		}
		cout << endl;
	}
}

void displayUnionSize(int n)
{
	for(int i=1; i<=n; i++)
	{
		cout << i << " : " << union_size[i] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int temp;
	for(int i=1; i<=n; i++)
	{
		cin >> temp;
		weight.pb(mp(temp, i));
		// w[i] = temp;
 	}
	sort(weight.begin(), weight.end());
	int x, y;
	while(m--)
	{
		cin >> x >> y;
		create_edge(x, y);
		create_edge(y, x);
	}
	initialise(n);
	int start = weight[0].S;
	queue<int> q1;
	q1.push(start);
	// visited[start] = true;
	while(!q1.empty())
	{
		int u = q1.front();
		q1.pop();
		visited[u] = true;
		for(auto i : graph[u])
		{
			if(visited[i] ==  false)
			{
				unison(u, i);
				q1.push(i);
			}
		}
	}
	display(n);
	displayUnionSize(n);
	long double ans = 0;
	for(auto i : weight)
	{
		ans += (ll)i.F * union_size[i.S];
		delete1(i.S);
	}
	ans *= 2;
	ans = ans/((ll)n * (n-1));
	cout << ans << endl;
	return 0;
}
