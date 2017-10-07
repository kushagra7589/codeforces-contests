#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

const int MAX_SIZE = 1e5 + 10;

const ll INF = 1e18 + 10;

int main()
{
	int n;
	ll p, q, r;
	ll P = -INF, Q = -INF, R = -INF;
	cin >> n >> p >> q >> r;
	ll a;
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		P = max(P, a * p);
		Q = max(Q, a * q);
		R = max(R, a * r);
	}
	cout << P + Q + R << endl;
	return 0;
}