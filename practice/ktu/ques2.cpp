#include <bits/stdc++.h>

using namespace std;
// const int MAX_SIZE = 1e4+10;
typedef long long ll;
// bool is_prime[MAX_SIZE];

// void mark_multiples(int a, int n)
// {
// 	for(int i=a*a; i<=n; i+=a)
// 	{
// 		is_prime[i] = false;
// 	}
// }

// void sieve(int n)
// {
// 	for(int i=2; i<=n; i++)
// 	{
// 		if(is_prime[i])
// 		{
// 			mark_multiples(i, n);
// 		}
// 	}
// }

// // int pow2[MAX_SIZE];

// ll pow2(int x, int n)
// {
// 	if(x == 1)
// 		return 2;
// 	if(x == 0)
// 		return 1;
// 	else
// 	{
// 		ll res = 1;
// 		res = pow2(x/2, n) % n;;
// 		if(x % 2 == 1)
// 		{
// 			res = (((res * res)%n) * 2)%n;
// 		}
// 		else
// 		{
// 			res = (res*res)%n;
// 		}
// 		return res % n;
// 	}
// }

int main()
{
	ios_base::sync_with_stdio(false);
	// sieve(10007);
	// for(int i=1; i<=100; i++)
	// {
	// 	cout << i << " " << is_prime[i] << endl;
	// }
	int t;
	cin >> t;
	int n;
	ll ans;
	for(int x = 1; x <= t; x++)
	{
		cin >> n;
		if(n == 2)
		{
			ans  = 0;
		}
		else 
		{
			ans = 1;
		}
		cout << "Case #" << x << ": " << ans << endl;
	}
	return 0;
}