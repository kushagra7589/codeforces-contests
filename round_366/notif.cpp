#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 3e5+10;

vector< vector<int> > unread(MAX_SIZE, 0);
vector<int> seg(4*MAX_SIZE, 0);
vector<int> lazy(4*MAX_SIZE, 0);

void update(int v, int L, int R, int x, int y, int z)
{
	if(lazy[v])
	{
		seg[v] += lazy[v] * (R-L+1);
		if(L < R)
		{
			lazy[2*v] += lazy[v];
			lazy[2*v + 1] += lazy[v];
		}
		lazy[v] = 0;
	}
	if(!(R < x || y < L))
	{
		if(x <= L && L <= R && R <= y)
		{
			seg[v] += (R-L+1)*z;
			lazy[2 * v] += z
			lazy[2 * v + 1] += z
		}
		else{
			int mid = (L + R)/2;
			update(2*v, L, mid, x, y, z);
			update(2*v + 1, mid+1, R, x, y, z);

			seg[v] = seg[2*v] + seg[2*v + 1];
		}
	}
}

int query(int v, int L, int R, int x, int y)
{
	if (lazy[v])
	{
		seg[v] += lazy[v] * (R - L + 1);
		if (L < R)
		{
			lazy[2 * v] += lazy[v];
			lazy[2 * v + 1] += lazy[v];
		}
		lazy[v] = 0	;
	}

	if (R < x or y < L)
	{
		return 0;
	}
	else if (x <= L <= R <= y)
	{
		return seg[v];
	}
	else{
		mid = (L + R) / 2;
		return query(2 * v, L, mid, x, y) + query(2 * v + 1, mid + 1, R, x, y);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, q;
	cin>>n>>q;
	int num_1 = 1, num_2 = 1, num_3 = 1;
	int type, x;
	for(int i=0; i<q; i++){
		cin>>type>>x;
		if(type == 1)
		{
			unread[x].push_back(num_1);
			update(1, 1, MAX_SIZE, num_1, num_1, 1);
		}
		else if(type == 2)
		{
			for(int j=0; i<unread[x].size(); j++){
				update()
			}
		}
		int ans = query(1, 1, n, 1, n);
		cout<<ans<<endl;
	}
	return 0;
}