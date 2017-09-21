#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		ll a, b, c;
		cin >> a >> b >> c;
		ll rect = a*b;
		ll sqr = c*c;
		ll m = (rect) % (sqr);
		ll ans;
		if(rect < sqr)
			ans = sqr;
		elseif(m < sqr - m)
		{
			ans = rect-m;
		}
		else
		{
			ans = rect + sqr - m;
		}
		cout << ans << endl;
	}
	return 0;
}