#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back

const int MAX_A = 1e6 + 10;
const int MAX_N = 5e5 + 10;

bool arr[MAX_A];
vector<ll> primes;
ll A[MAX_N];

set<ll> check;

int main()
{
	ios_base::sync_with_stdio(false);
	memset(arr, true, sizeof(arr));
	arr[1] = false;
	for(int i = 2; i  * i < MAX_A; i++)
	{
		if(arr[i])
		{
			for(int j = i * i; j < MAX_A; j += i)
			{
				arr[j] = false;
			}
		}
	}
	for(int i = 1; i < MAX_A; i++)
	{
		if(arr[i])
			primes.pb(i);
	}
	int n;
	ll x, y;
	ll M = 1e18;
	cin >> n >> x >> y;
	for(int i = 1; i <= n; i++)
	{
		cin >> A[i];
		ll k = A[i];
		int y = 0;
		while(k > 1)
		{
			bool flag = false;
			// cout << k << " " << primes[y] << endl;
			while(k % primes[y] == 0)
			{
				flag = true;
				k /= primes[y];
			}
			if(flag)
				check.insert(primes[y]);
			y++;
		}

	}
	for(auto &i : primes)
	{
		ll sum = 0;
		for(int j = 1; j <= n; j++)
		{
			if(sum >= M)
				break;
			ll k = (A[j] % i) ? i - (A[j] % i) : 0;
			sum += min(x, y * k);
		}
		M = min(sum, M);
	}
	cout << M << endl;
	return 0;
}