#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

ll pow2[51] = {1};

int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	pow2[0] = 1;
	for(int i=1; i<=50; i++)
	{
		pow2[i] = pow2[i-1]*2;
	}
	cin >> n >> k;
	for(int i=1; i<=50; i++)
	{
		if((k - pow2[i-1]) % pow2[i] == 0)
		{
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}