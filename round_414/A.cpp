#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	ll a, b, c;
	cin >> a >> b >> c;
	int n;
	cin >> n;
	ll x;
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		if(x > b && x < c)
		{
			ans += 1;
		}
	}
	cout << ans << endl;
	return 0;
}