#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define fast_io() ios_base::sync_with_stdio(false);

const int MAX_SIZE = 1e5 + 10;

vector<int> graph[MAX_SIZE];
vector<bool> visited(MAX_SIZE, false);

double dfs(int s)
{
	visited[s] = true;
	double sum = 0;
	int cnt = 0;
	for(auto &u : graph[s]) {
		if(!visited[u]) {
			sum += 1 + dfs(u);
			cnt += 1;
		}
	}
	// cout << s << " " << sum << " " << cnt << endl;
	if(cnt == 0)
		return 0;
	sum /= cnt;
	return sum;
}

int main() {
	fast_io();
	int n;
	cin >> n;
	int a, b;
	for(int i = 1; i < n; i++) {
		cin >> a >> b;
		graph[a].pb(b);
		graph[b].pb(a);
	}
	double sum = dfs(1);
	printf("%.8lf\n", sum);
	return 0;
}