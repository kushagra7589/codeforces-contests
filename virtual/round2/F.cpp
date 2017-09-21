#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 1e5 + 10; 
ll n;  
ll t[2 * N];

void build() {
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] +  t[i<<1|1];
}

void modify(int p, ll value) {
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] +  t[p^1];
}

ll query(int l, int r) {
	if(l >= r)
		return 0;
 	ll res = 0;
 	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
 	  if (l&1) res += t[l++];
 	  if (r&1) res += t[--r];
 	}
 	return res;
}

ll A[N];

ll fenwick(ll x)
{
	ll m = 2;
	ll ans = 1;
	while(x % m == 0)
	{
		ans *= 2;
		m *= 2;
	}
	return ans;
}

int main()
{
	freopen ("fenwick.in","r+",stdin);
	freopen ("fenwick.out","w+",stdout);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> t[i + n];
	}
	if(n == 1)
	{
		cout << t[n] << endl;
		return 0;
	}
	build();
	for(int i = 0; i < n; i++)
	{
		ll j = (i+1) + 1 - fenwick((i+1) + 1);
		A[i] = (j > i) ? t[i + n] : -1 * query(j, i);
		modify(i, A[i]);
	}
	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}