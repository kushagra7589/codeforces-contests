#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair

int main()
{
	ios_base::sync_with_stdio(false);
	ll k, r;
	cin >> k >> r;
	k = k % 10;;
	ll temp;
	ll ans;
	for(int i = 1; i<10; i++)
	{
		temp = k * i;
		if(temp%10 == r || temp %10 == 0)
		{
			ans = i;
			cout << ans << endl;
			return 0;
		}
	}
	return 0;
}