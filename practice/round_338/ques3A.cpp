#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 1e5+10;
const int M = 1e9+7;

ll power(ll x, ll y)
{
	ll res = 1;
	while(y > 0)
	{
		if(y & 1)
			res = (res*x) % M;
		y = y>>1;
		x = (x*x)%M;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int m;
	cin >> m;
	unordered_map<ll, ll> count;
	ll p;
	ll n = 1;
	for(int i = 0; i < m; i++)
	{
		cin >> p;
		if(count.find(p) == count.end())
			count[p] = 0;
		count[p] += 1;
		n = (n*p) % M;
	}
	ll num = 1;
	ll root_n = 1;
	for(auto i : count)
	{
		root_n = (root_n * power(i.F, i.S/2))%M;
		num = (num * (i.S + 1))%(M-1);
	}
	ll res = power(n, num/2);
	res = (res * ((num%2)?root_n:1))%M;
	cout << res << endl;
	return 0;

}
