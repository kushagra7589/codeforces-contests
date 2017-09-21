#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 2e4+10;
const int MAX_I = 60;
const int M = 1e9+7;
const int K = 14;

// ll Table[MAX_SIZE][K+1];
vector< vector< unordered_map<int, int > > > table(MAX_SIZE, vector< unordered_map<int, int> >(K+1));


int find_k(int n)
{
	int ans = 1;
	int k = -1;
	while(ans <= n)
	{
		ans<<=1;
		k+=1;
	}
	return k;
}

ll power(ll a, ll b)
{
	ll res = 1;
	while(b > 0)
	{
		if(b&1)
			res = (res*a)%M;
		a = (a*a)%M;
		b>>=1;
	}
	return (res)%M;
}

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};

vector< unordered_map<int, int> > factorisation(61);

void get_factorisation(int i)
{
	for(int j=0; primes[j] <= i; j++)
	{
		int x = i;
		while(x % primes[j])
		{
			factorisation[i][primes[j]] += 1;
			x /= primes[j];
		}
	}
}

unordered_map<int, int> lcm(unordered_map<int, int> &a, unordered_map<int, int> &b)
{
	unordered_map<int, int> res;
	for(int i=0; i<17; i++)
	{
		res[primes[i]] = max(a[primes[i]], b[primes[i]]);
	}
	return res;
}


void create_sparse_table(int n, int k)
{
	for(int i=0; i<n; i++)
	{
		 table[i][0] = factorisation[i];
	}
	for(int j=1; j<=k; j++)
	{
		for(int i=0; i<= n - (1<<j); ++i)
		{
			table[i][j] = lcm(table[i][j-1], table[i + (1 << (j-1))][j-1]);
		}
	}
}

ll query()

int main()
{
	ios_base::sync_with_stdio(false);
	int k = find_k(MAX_SIZE);
	cout << k << endl;
	for(int i=1; i<=MAX_I; i++)
	{
		for(int j=0; j<17; j++)
		{
			factorisation[i][primes[j]] = 0;
		}
		get_factorisation(i);
	}
	// int n, m;
	// cin >> n >> m;

	return 0;
}