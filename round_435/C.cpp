#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

set<ll> A;

int main()
{
	ll n, x;
	cin >> n >> x;
	if(n == 2 && x == 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	if(n % 2 == 0)
	{
		A.insert(x);
		A.insert(0);
		n -= 2;
	}
	else
	{
		A.insert(x);
		n -= 1;
	}
	int cnt = 0;
	int i;
	for(i = 1; i <= n/2; i++)
	{
		if(i != x)
		{
			A.insert(i);
			A.insert(i ^ x);
			cnt += 2;
		}
	}
	if(cnt < n)
	{
		A.insert(i);
		A.insert(x ^ i);
	}
	for(auto &i : A)
	{
		cout << i << " ";
	}
	return 0;
}