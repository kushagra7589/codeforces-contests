#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair

const int MAX_SIZE = 2e4+10;

vi arr(MAX_SIZE);
vector< unordered_map<int, int> > factorisation(61);
vector< unordered_map<int, int > > lcm(MAX_SIZE); 

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

ll power(int a, int b)
{
	ll res = 1;
	for(int i=1; i<=b; i++)
	{
		res = res * a;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	for(int i=0; i<MAX_SIZE; ++i)
	{
		for(int j=0; j<17; j++)
		{
			lcm[i][primes[j]] = 0;
		}
	}
	for(int i=1; i<=60; i++)
	{
		for(int j=0; j<17; j++)
		{
			factorisation[i][primes[j]] = 0;
		}
		for(int j=0; primes[j] <= i; ++j)
		{
			int x = i;
			while(x % primes[j] == 0)
			{
				factorisation[i][primes[j]] += 1;
				x = x/primes[j];
			}
		}
	}
	cout << 32 << endl;
	for(int j=0; j<17; j++)
	{
		cout << primes[j] << " : " << factorisation[32][primes[j]] << endl;
	}
	int n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
	}
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<17; j++)
		{
			lcm[i][primes[j]] = max(lcm[i-1][primes[j]], factorisation[arr[i]][primes[j]]);
		}
	}
	// ll ans = 1;
	// for(int j=0; j<17; j++)
	// {
	// 	ans = ans * power(primes[j], lcm[n][primes[j]]);
	// }
	// cout << ans <<  endl;
	
	return 0;
}