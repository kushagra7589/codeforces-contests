#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll ans  = 2;
	cout << ans << endl;
	for(ll i=2; i<=n; i++)
	{
		ans = i*(i+1)*(i+1) - i + 1;
		cout << ans << endl; 
	}
	return 0;
}