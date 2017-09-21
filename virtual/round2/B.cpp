#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define F first
#define S second

/* seg tree implementaton : http://codeforces.com/blog/entry/18051 */

const int N = 2e5 + 10; 
ll n;  
ll t[2 * N];

void build() {
  for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

void modify(int p, ll value) {
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = max(t[p], t[p^1]);
}

ll query(int l, int r) { 
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(res, t[--r]);
  }
  return res;
}

int main()
{
	freopen ("billboard.in","r+",stdin);
	freopen ("billboard.out","w+",stdout);
	ios_base::sync_with_stdio(false);
	ll h, w;
	cin >> h >> w >> n;
	for(int i = 0; i < n; i++)
	{
		t[i + n] = w;
	}
	build();
	ll nu = n;
	n = min(h, n);
	ll x;
	for(int i = 0; i < nu; i++)
	{
		cin >> x;
		ll L = 0;
		ll H = n;
		ll ans;
		while(L < H)
		{
			ll mid = (L + H)/2;
			ll res = query(L, mid + 1);
			// cout << L << " " << H << " " << res << endl; 
			if(res < x)
			{
				L = mid + 1;
			}
			else
			{
				H = mid;
			}
		}
		if(L == n)
			cout << -1 << endl;
		else
		{
			cout << L + 1 << endl;
			modify(L, t[L + n] - x);
		}
	}
	return 0;
}