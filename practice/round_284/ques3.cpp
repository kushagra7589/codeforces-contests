#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll side(ll a, ll b, ll c, ll x, ll y)
{
	return (a*x + b*y + c > 0) ? 1 : -1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n;
	cin >> n;
	ll a, b, c;
	ll steps = 0;
	for(int i=0; i<n; i++)
	{
		cin >> a >> b >> c;
		steps += (side(a, b, c, x1, y1) * side(a, b, c, x2, y2) > 0) ? 0 : 1;
	}	
	cout << steps << endl;
	return 0;
}