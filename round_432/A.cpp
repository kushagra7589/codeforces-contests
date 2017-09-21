#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;

int main()
{
	ll n, k, t;
	cin >>  n >> k >> t;
	if(t <= k)
	{
		cout << t;
	}
	else if(t <= n)
	{
		cout << k;
	}
	else
	{
		cout << k - (t - n);
	}
	return 0;
}