#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;

int main()
{
	ll l, r, x, y, k;
	cin >> l >> r >> x >> y >> k;
	for(ll i = l; i <= r; i++)
	{
		if(i % k == 0)
		{
			ll A = i / k;
			if(x <= A && A <= y)
			{
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}