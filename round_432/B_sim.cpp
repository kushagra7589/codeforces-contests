#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dist2(ll one[2], ll two[2])
{
	return (one[0] - two[0])*(one[0] - two[0]) + (one[1] - two[1])*(one[1] - two[1]); 
}

int main()
{
	ll a[2], b[2], c[2];
	cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
	if(((a[0] - b[0]) * (c[1] - b[1])) == ((b[0] - c[0]) * (b[1] - a[1])))
	{
		cout << "No" << endl;
		return 0;
	}
	if(dist2(a, b) == dist2(b, c))
	{
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}