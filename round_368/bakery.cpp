#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e5+10;
const int INF = 1e9+10;
vector< vector<pair<int, int> > > graph(MAX_SIZE);
bool bakery[MAX_SIZE] = {false};
// vector< int > minimum_dist;
void make_edge(int x, int y, int w)
{
	graph[x].push_back(make_pair(y, w));
}

void delete_from_graph(int x)
{
	for(vector< pair<int, int > >::iterator i = graph[x].begin(); i != graph[x].end(); i++)
	{
		int u = (*i).first;
		// int w = (*i).second;
		if(bakery[u] == true) {
			// cout << "Being deleted : " << u << " " << w << endl; 
			graph[x].erase(i);
			i--;
		}
	}
}

int get_min(int *A, int n)
{
	int MIN_VAL = INF;
	int curr_min = INF;
	for(int i=0; i<n; ++i) {
		for(int j=0; j<graph[A[i]].size(); j++) {
			if(bakery[graph[A[i]][j].first] == false) {
				if(graph[A[i]][j].second < curr_min)
					curr_min = graph[A[i]][j].second;
			}
		}
		if(curr_min < MIN_VAL)
			MIN_VAL = curr_min;
	}
	return MIN_VAL ;
}

void display(int n)
{
	for(int i=1; i<=n; i++) {
		cout << i ;
		for(int j=0; j<graph[i].size(); j++) {
			cout << "->(" << graph[i][j].first << ", " << graph[i][j].second << ") ";
		}
		cout << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin>>n>>m >> k;
	int x, y, w;
	for(int i=0; i<m; i++) {
		cin >> x >> y >> w;
		make_edge(x, y, w);
		make_edge(y, x, w);
	}
	// int k;
	// cin>>k;
	// display(n);
	int arr[MAX_SIZE];
	for(int i=0; i<k; i++) {
		cin>>x;
		// delete_from_graph(x);
		arr[i] = x;
		bakery[x] = true;
	}
	// for(int i = 1; i<= n; i++)
		// cout << i << " --> " << bakery[i] << endl;
	// for(int i=0; i<k; i++) {
	// 	delete_from_graph(arr[i]);
	// }
	// display(n);
	int ans = get_min(arr, k);
	if(ans  == INF)
		cout << "-1" <<endl;
	else
		cout << ans << endl;
	return 0;
}
