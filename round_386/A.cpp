#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first 
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	ll a, b, c;
	cin >> a >> b >> c;
	ll ans = min(a, min(b/2, c/4));
	cout << ans * 7 << endl;
	return 0;
}