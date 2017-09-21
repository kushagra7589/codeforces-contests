#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second


int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	if(n == 1)
		cout << 3;
	else if(n == 2)
		cout << 4;
	else if(n % 2 == 1)
		cout << 1;
	else
	{
		cout << n-2;
	}
	cout << endl;
	return 0;
}