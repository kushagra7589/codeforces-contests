#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	ll l1, l2, r1, r2, k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	ll l = max(l1, l2);
	ll r = min(r1, r2);
	ll tim = max(r - l + 1, 0LL);
	if(l <= k && k <= r)
	{
		tim -= 1;
	}
	cout << tim << endl;
	return 0;
}