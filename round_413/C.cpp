#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define F first
#define S second

const int N = 1e5+10;

// int n; 

void build(ll t[], int n) { 
  for (int i = n - 1; i > 0; --i) t[i] = max(t[i<<1], t[i<<1|1]);
}

ll query(int l, int r, ll t[], int n) { 
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res = max(res, t[l++]);
    if (r&1) res = max(res, t[--r]);
  }
  return res;
}

vector< pair<ll, ll> > coin;
vector< pair<ll, ll> > diamond;

ll beautyC[2*N] = {0};
ll beautyD[2*N] = {0};

vector<ll> priceC,  priceD;


int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	ll c, d;
	cin >> n >> c >> d;
	ll b, p;
	char C;
	ll max_C = 0, max_D = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> b >> p >> C;
		if(C == 'C')
		{
			if(p <= c)
				max_C = max(b, max_C);
			coin.pb(mp(p, b));
		}
		else
		{
			if(p <= d)
				max_D = max(max_D, b);
			diamond.pb(mp(p, b));
		}
	}
	ll max1, max2, max3;
	if(max_C == 0 || max_D == 0)
		max1 = 0;
	else
		max1 = max_C + max_D;
	sort(coin.begin(), coin.end());
	sort(diamond.begin(), diamond.end());
	int n1 = coin.size();
	priceC.resize(n1);
	int n2 = diamond.size();
	priceD.resize(n2);
	for(int i = 0; i < n1; i++)
	{
		beautyC[i + n1] = coin[i].S;
		priceC[i] = coin[i].F;
	}
	for(int i = 0; i < n2; i++)
	{
		beautyD[i + n2] = diamond[i].S;
		priceD[i] = diamond[i].F;
	}
	max2 = 0;
	build(beautyC, n1);
	for(int i = 0; i < n1; i++)
	{
		auto u = upper_bound(priceC.begin(), priceC.end(), c - priceC[i]);
		int r = u - priceC.begin();
		if(r - 1 <= i)
			break;
		else
			max2 = max(max2, query(i, i + 1, beautyC, n1) + query(i + 1, r, beautyC, n1));
	}
	max3 = 0;
	build(beautyD, n2);
	for(int i = 0; i < n2; i++)
	{
		auto u = upper_bound(priceD.begin(), priceD.end(), d - priceD[i]);
		int r = u - priceD.begin();
		if(r - 1 <= i)
			break;
		else
			max3 = max(max3, query(i, i + 1, beautyD, n2) + query(i + 1, r, beautyD, n2));
	}
	// cout << max1 << " " << max2 << " " << max3 << endl;
	cout << max(max1, max(max2, max3)) << endl;
	return 0;
}