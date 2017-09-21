#include <bits/stdc++.h>

using namespace std;
const int M = 1e9+7;
typedef long long ll;

ll power(ll x, ll y)
{
    ll res = 1;      
    x = x % M;  
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % M;
        y = y>>1; // y = y/2
        x = (x*x) % M;  
    }
    return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int m;
	cin >> m;
	ll n = 1;
	ll p;
	unordered_map<ll, int> count;
	for(int i=0; i<m; i++)
	{
		cin >> p;
		if(count.find(p) == count.end())
		{
			count[p] = 0;
		}
		count[p] += 1;
		n = (n*p)%M;
	}
	ll num = 1;
	for(auto i : count)
	{
		num = (num * (i->second + 1));
	}
	return 0;
}