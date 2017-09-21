#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

#define fast_cin() ios_base::sync_with_stdio(false);

int main()
{
	ll n, k;
	cin >> n >> k;
	ll r = n / k;
	if(r % 2 == 0)
	{
		cout << "NO" << endl;
	}
	else
	{
		cout << "YES" << endl;
	}
	return 0;
}