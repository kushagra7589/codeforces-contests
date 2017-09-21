#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const double INF = 1e12+10;

map< pll, vector< pair< pll, double> > > graph;
vector< pll > nodes;
vector< pll > current_subway;
map< pll, double > dis;

void create_edge(pll const &a, pll const &b, double w)
{
	if(graph.find(a) == graph.end())
		graph.insert(pair< pll, vector< pair<pll, double > > >(a, vector< pair< pll, double> >()));
	graph[a].pb(mp(b, w));
	
}

double distance (pll const &a, pll const &b)
{
	return sqrt((double)(a.F - b.F)*(a.F - b.F) + (a.S - b.S)*(a.S - b.S));
}

void djiktra(pll const &x)
{
	for(auto i : nodes)
	{
		dis.insert(mp(i, INF));
	}
	priority_queue< pair< double, pll>, vector< pair< double, pll > >, greater< pair< double, pll> > > pq;
	pq.push(mp(0, x));
	dis[x] = 0;
	while(!pq.empty())
	{
		pll u = pq.top().S;
		pq.pop();
		for(auto i : graph[u])
		{
			pll v = i.F;
			double weight = i.S;
			if(dis[v] > dis[u] + weight)
			{
				// cout << v.F << ":" << v.S << " = " << dis[v] << " -> ";
				dis[v] = dis[u] + weight;
				// cout << dis[v] << endl;
				pq.push(mp(dis[v], v));
			}
		}
	}
}

ll roundOff(double a)
{
	if(a - floor(a) < 0.5)
		return floor(a);
	else
		return ceil(a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll homeX, homeY, schoolX, schoolY;
	cin >> homeX >> homeY >> schoolX >> schoolY;
	nodes.pb(mp(homeX, homeY));
	nodes.pb(mp(schoolX, schoolY));
	double tim1 = distance(nodes[0], nodes[1])*6.0/1000.0;
	create_edge(nodes[0], nodes[1], tim1);
	create_edge(nodes[1], nodes[0], tim1);
	ll x = 0;
	ll y = 0;
	while(true)
	{
		if(!(cin >> x >> y))
			break;
		while(x != -1)
		{
			pll curr;
			curr = mp(x, y);
			for(auto i : nodes)
			{
				double tim = distance(curr, i)*6.0/1000.0;
				create_edge(curr, i, tim);
				create_edge(i, curr, tim);
			}
			for(auto i : current_subway)
			{
				double tim = distance(curr, i)*6.0/1000.0;
				create_edge(curr, i, tim);
				create_edge(i, curr, tim);
			}
			if(!current_subway.empty())
			{
				pll prev = current_subway[current_subway.size() - 1];
				double tim = distance(curr, prev)*3.0/2000.0;
				create_edge(curr, prev, tim);
				create_edge(prev, curr, tim);
			}
			current_subway.pb(curr);
			cin >> x >> y;
		}
		for(auto i : current_subway)
		{
			nodes.pb(i);
		}
		current_subway.clear();
	}

	// for (auto i : graph)
	// {
	// 	cout << i.F.F << ":" << i.F.S;
	// 	for(auto j : i.S)
	// 	{
	// 		cout << "  ->" << j.F.F << ":" << j.F.S << "  = " << j.S ;
	// 	}
	// 	cout << endl;
	// 	cout << "-------------------------------------------" << endl;
	// }

	djiktra(mp(homeX, homeY));
	double ans  = dis[mp(schoolX, schoolY)];
	ll res = roundOff(ans);
	// cout << setprecision(0) << fixed << ans << endl;

	cout << res << endl;
	
	return 0;
}