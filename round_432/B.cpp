#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;

int main()
{
	ll a[2], b[2], c[2];
	cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
	if(((a[0] - b[0]) * (c[1] - b[1])) == ((b[0] - c[0]) * (b[1] - a[1])))
	{
		cout << "No" << endl;
		return 0;
	}
	ll N = ((b[1] - a[1]) * (c[1]*c[1] + c[0]*c[0] - b[0]*b[0] - b[1]*b[1])) - ((c[1] - b[1]) * (b[1]*b[1] + b[0]*b[0] - a[0]*a[0] - a[1]*a[1]));
	ll D = (ll)2 * (((c[1] - b[1]) * (a[0] - b[0])) - ((b[1] - a[1]) * (b[0] - c[0])));
	// cout << D << endl;
	// cout << (double)N / D << endl;
	// cout << N << endl;
	ll lhs = (ll)2 * (b[1] - a[1]) * (a[0]*a[0] + a[1]*a[1] - c[0]*c[0] - c[1]*c[1]) * D;
	ll rhs = ((ll)4 * N * (a[0] - c[0]) * (b[1] - a[1])) + (ll)2 * (a[1] - c[1]) * (((ll)2 * (a[0] - b[0]) * N) + D * (b[1]*b[1] + b[0]*b[0] - a[0]*a[0] - a[1]*a[1]));
	// ll lhs = (a[0]*a[0] + a[1]*a[1] - c[0]*c[0] - c[1]*c[1]) * den * (ll)2 * (b[1] - a[1]);
	// ll rhs = den * (ll)2 * (b[1] - a[1]) * (a[0] - c[0]);
	// rhs -= (a[1] - c[1]) * (((ll)2 * (a[0] - b[0]) * A) + (den * (b[1]*b[1] + b[0]*b[0] - a[0]*a[0] - a[1]*a[1])));
	// cout << lhs << " " << rhs << endl;
	if (lhs == rhs && (((ll)2 * b[1] * (c[1] - a[1])) == (((ll)2 * (a[0] - c[0]) * b[0]) + (c[1]*c[1] + c[0]*c[0] - a[0]*a[0] - a[1]*a[1]))))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	return 0;
}