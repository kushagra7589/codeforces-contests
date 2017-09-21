#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

map<int, vector<int> > graph;

int main()
{
	int n;
	cin >> n;
	int x;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> x;
			if(graph.find(x) == graph.end())
			{
				graph[x] = vector<int>();
			}
		}
	}
	for(int i = )
}