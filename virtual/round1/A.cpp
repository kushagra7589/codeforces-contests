#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fast_cin() ios_base::sync_with_stdio(0)

typedef long long ll;
typedef long double ld;

const int MAX_SIZE = 5010;

vector<int> graph[MAX_SIZE];
bool visited[MAX_SIZE];
int indegre[MAX_SIZE];
map<int, int> order;
vector<int> A;

void dfs_topo(int i, int index)
{
	visited[i] = true;
	cout << i << endl;
	A[i] = index;
	for(auto &u : graph[i])
	{
		if(visited[u] == false)
		{
			dfs_topo(u, index + 1);
		}
		else
		{
			if(index > A[u])
				A[u] = index;
		}
	}
}

int main()
{
	fast_cin();
	int a, b, e, p;
	cin >> a >> b >> e >> p;
	int x, y;
	A.resize(e);
	for(int i = 0; i < MAX_SIZE; i++)
	{
		indegre[i] = 0;
		visited[i] = false;
	}

	for(int i = 0; i < p; i++)
	{
		cin >> x  >> y;
		graph[x].pb(y);
		indegre[y] += 1;
	}
	for(int i = 0; i < e; i++)
	{
		if(visited[i] == false && indegre[i] == 0)
		{
			dfs_topo(i, 0);
		}
	}
	for(auto &i : A)
	{
		cout << i << " ";
	}
	cout << endl;
	sort(A.begin(), A.end());
	for(int i = 0 ; i < e; i++)
	{
		if(order.find(A[i]) == order.end())
			order[A[i]] = 0;
		order[A[i]] += 1;
	}
	int ans = 0;
	for(auto i : order)
	{
		if(ans + i.S <= a)
			ans += i.S;
		else
			break;
	}
	cout << ans << endl;
	ans = 0;
	for(auto i : order)
	{
		if(ans + i.S <= b)
			ans += i.S;
		else
			break;
	}
	cout << ans << endl;
	ans = 0;
	for(auto i : order)
	{
		if(ans >= b)
			break;
		else
			ans += i.S;
	}
	ll sum = 0;
	for(auto i : order)
	{
 		sum += i.S;
	}
	cout << sum - ans << endl;
	return 0;
}