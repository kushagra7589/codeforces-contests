#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct segnode
{
	ll cnt[10];
	ll quo[10];
};

const int MAX_SIZE = 1e4 + 10;

segnode seg[4 * MAX_SIZE];
ll arr[MAX_SIZE];
ll m;

void build(int v, int l, int r)
{
	if(l == r)
	{
		for(int i = 0; i < m; i++)
		{
			seg[v].cnt[i] = 0;
			seg[v].quo[i] = 0;
		}
		seg[v].cnt[arr[l] % m] = 1;
		seg[v].quo[arr[l] % m] = arr[l] - (arr[l] % m);
		return;
	}
	int mid = (l + r) / 2;
	build(2 * v, l, mid);
	build(2 * v + 1, mid + 1, r);
	for(int i = 0; i < m; i++)
	{
		seg[v].cnt[i] = seg[2*v].cnt[i] + seg[2*v + 1].cnt[i];
		seg[v].quo[i] = seg[2*v].quo[i] + seg[2*v + 1].quo[i];
	}
}

ll query(int v, int l, int r, int x, int y, int mod)
{
	if(y < l || r < x)
		return 0;
	if(x <= l && r <= y)
	{
		// cout << l << " | " << r << " -> " << seg[v].cnt[mod] << " ,  " << seg[v].quo[mod] << endl; 
		return seg[v].cnt[mod] * mod + seg[v].quo[mod];
	}
	ll ans = 0;
	int mid = (l + r) / 2;
	ans += query(2 * v, l, mid, x, y, mod);
	ans += query(2 * v + 1, mid + 1, r, x, y, mod);
	return ans;
}

void update(int v, int l, int r, int p, ll x)
{
	if(!(l <= p && p <= r))
		return;
	if(l == r)
	{
		for(int i = 0; i < m; i++)
		{
			seg[v].cnt[i] = 0;
			seg[v].quo[i] = 0;
		}
		seg[v].cnt[x % m] = 1;
		seg[v].quo[x % m] = x - (x % m);
		return;
	}
	int mid = (l + r) / 2;
	update(2 * v, l, mid, p, x);
	update(2 * v + 1, mid + 1, r, p, x);
	for(int i = 0; i < m; i++)
	{
		seg[v].cnt[i] = seg[2*v].cnt[i] + seg[2*v + 1].cnt[i];
		seg[v].quo[i] = seg[2*v].quo[i] + seg[2*v + 1].quo[i];
	}
}

int main()
{
	int n;
	cin >> n >> m;
	// cerr << m << endl;
	memset(seg, 0, sizeof(seg));
	for(int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, 1, n);
	int q;
	cin >> q;
	string s;
	int a, b, c;
	while(q--)
	{
		cin >> s;
		if(s == "s")
		{
			cin >> a >> b >> c;
			cout << query(1, 1, n, a, b, c) << endl;
		}
		else if(s == "+")
		{
			cin >> a >> b;
			arr[a] += b;
			update(1, 1, n, a, arr[a]);
			cout << arr[a] << endl;
		}
		else if(s == "-")
		{
			cin >> a >> b;
			if(arr[a] >= b)
			{
				arr[a] -= b;
				update(1, 1, n, a, arr[a]);
				cout << arr[a] << endl;
			}	
			else
			{
				cout << arr[a] << endl;
			}
		}
	}
	return 0;
}