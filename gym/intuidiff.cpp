#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define F first
#define S second

const int N = 1e5 + 10;  // limit for array size
int n;  // array size
ll t[2 * N] = {0};

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

void modify(int p, ll value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

ll query(int l, int r) {  // sum on interval [l, r)
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(res, t[--r]);
  }
  return res;
}

set<pair<ll, ll > > starts; 
map<int, ll> weights;
map<ll, int> index1;
vector< pair<ll, ll> > input;

int main()
{
	cin >> n;
	ll a, b;
	for(int i = 0; i < n; i++)
	{
		cin >> a >> b;
		starts.insert({a, b - a + 1});
		input.pb({a, b});
	}
	int i = 0;
	for(auto &s: starts)
	{
		index1[s.F] = i;
		weights[i] = s.S;
		i++;
	}
	int NN = i;
	for(int i = 0; i < n; i++)
	{
		int x = index1[input[i].F];
		// cout << x << " : " << query(x, x + 1) << " | " << weights[x] << " | " << query(0, x) << endl;
		modify(x, max(query(x, x + 1), weights[x] + query(0, x)));
	}
	ll ans = query(0, N);
	cout << ans;
	return 0;
}