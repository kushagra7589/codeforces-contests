#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = (1 << 16) +10;

typedef long long ll;

vector<pair<int, int> > edges;

queue<int> q;

vector<int> xor_sum(MAX_SIZE);
vector<int> v_degree(MAX_SIZE);

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int degree, s;
	for(int i=0; i<n; i++)
	{
		cin >> degree >> s;
		if(degree == 1)
		{
			q.push(i);
		}
		v_degree[i] = degree;
		xor_sum[i] = s;
	}
	int i, x;
	while(!q.empty())
	{
		i = q.front();
		q.pop();
		x = xor_sum[i];
		if(v_degree[i] > 0)
		{
			edges.push_back(make_pair(i, x));
			xor_sum[x] = xor_sum[x]^i;
			v_degree[x] -= 1;
			if(v_degree[x] == 1)
			{
				q.push(x);
			}
		}
	}
	cout << edges.size() <<  endl;
	for(int i=0; i<edges.size(); i++)
	{
		cout << edges[i].first << " " << edges[i].second << endl;
	}
	return 0;
}