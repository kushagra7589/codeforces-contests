#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;

vector<ll> primes;
bool arr[(int)1e6 + 10] = {false};
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll x, y;
	memset(arr, true, sizeof(arr));
	for(ll i = 2; i * i <= 1e6; i++)
	{	
		if(arr[i])
		{
			for(ll j = i * i; j <= 1e6; j += i)
			{
				arr[j] = false;
			}
		}
	}
	ll cnt = 0;
	for(ll i = 2; i <= 1e6; i++)
	{
		if(arr[i])
		{
			primes.pb(i);
			cnt += 1;
		}
	}
	cout << cnt << endl;
	return 0;
}