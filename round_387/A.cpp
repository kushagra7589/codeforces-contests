#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define F first 
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll ans  = sqrt(n);
	int flag = 0;
	while(flag == 0)
	{
		if(n % ans == 0)
		{
			flag = 1;
		}
		else
		{
			ans--;
		}
	}
	cout << ans << " " << n/ans << endl;
	return 0;
}