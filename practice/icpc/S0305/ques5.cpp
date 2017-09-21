#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define RIGHT(x) x<<1|1
#define LEFT(x) x<<1
#define PARENT(x) x>>1

const int MAX_SIZE = 300;
const int INF = 1e9+1;
vector< pii > points;

vector< int > seg(4*MAX_SIZE);

void build_max_tree(int v, int l, int r, int *seg)
{
	if(l == r)
	{
		seg[v] = points[l].S;
		return;
	}
	else
	{
		int mid = (l+r)/2;
		build_max_tree(LEFT(v), l, mid, seg);
		build_max_tree(RIGHT(v), mid+1, r, seg);
		seg[v] = max(seg[LEFT(v)], seg[RIGHT(v)]);
	}
}

void build_min_tree(int v, int l, int r, int *seg)
{
	if(l == r)
	{
		seg[v] = points[l].S;
		return;
	}
	else
	{
		int mid = (l+r)/2;
		build_min_tree(LEFT(v), l, mid, seg);
		build_min_tree(RIGHT(v), mid+1, r, seg);
		seg[v] = min(seg[LEFT(v)], seg[RIGHT(v)]);
	}
}

ll querymax(int v, int l, int r, int x, int y, int *seg)
{
	if(y < l || r < x)
		return -INF;
	else if(x <= l && r <= y)
		return seg[v];
	else
	{
		int mid = (l+r)/2;
		int first = querymax(LEFT(v), l, mid, x, y, seg);
		int second = querymax(RIGHT(v), mid+1, r, x, y, seg);
		return max(first, second);
	}
}

int querymin(int v, int l, int r, int x, int y, int *seg)
{
	if(y < l || r < x)
		return INF;
	else if(x <= l && r <= y)
		return seg[v];
	else
	{
		int mid = (l+r)/2;
		int first = querymin(LEFT(v), l, mid, x, y, seg);
		int second = querymin(RIGHT(v), mid+1, r, x, y, seg);
		if(first == INF)
			return second;
		else if(second == INF)
			return first;
		return min(first, second);	
	}
}

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int x, y;
	while(t--)
	{
		int seg1[4*MAX_SIZE];
		int seg2[4*MAX_SIZE];
		int n;
		cin >> n;
		points.pb(mp(INF, INF));
		for(int i=0; i<n; i++)
		{
			cin >> x >> y;
			points.pb(mp(x, y));
		}
		sort(points.begin()+1, points.end());
		int jump = n/2;
		build_max_tree(1, 1, n, seg1);
		build_min_tree(1, 1, n, seg2);
		ll area = INF;
		for(int i=1; i+jump <= n; i++)
		{	
			ll x2 = points[i+jump].F;
			ll x1 = points[i].F;
			ll y2 = querymax(1, 1, n, i, i+jump,seg1);
			ll y1 = querymin(1, 1, n, i, i+jump,seg2);
			// cout << "X1 = " << x1 << " Y1 = " << y1 << " X2 = " << x2 << " Y2 = " << y2 << endl;  
			ll temp = (x2 - x1)*(y2 - y1);
			area = min(area, temp);
		}
		ll ans = area;
		// cout << area << endl;
		for(int i=1; i<=n; i++)
		{
			swap(points[i].F, points[i].S);
		}
		sort(points.begin()+1, points.end());
		jump = n/2;
		build_max_tree(1, 1, n, seg1);
		build_min_tree(1, 1, n, seg2);
		area = INF;
		for(int i=1; i+jump <= n; i++)
		{	
			ll x2 = points[i+jump].F;
			ll x1 = points[i].F;
			ll y2 = querymax(1, 1, n, i, i+jump,seg1);
			ll y1 = querymin(1, 1, n, i, i+jump,seg2);
			// cout << "X1 = " << x1 << " Y1 = " << y1 << " X2 = " << x2 << " Y2 = " << y2 << endl;  
			ll temp = (x2 - x1)*(y2 - y1);
			area = min(area, temp);
		}
		ans = min(ans, area);
		cout << ans << endl;
		points.clear();
	}
	return 0;
}