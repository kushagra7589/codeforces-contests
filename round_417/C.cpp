#include <bits/stdc++.h>

using namespace std;

#define fast_io() ios_base::sync_with_stdio(false);
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

int main()
{
	bool a = false, b = false, c = false, d = false;
	int x, y, z, p1, p2, p3, p4;
	cin >> x >> y >> z >> p1;
	if(((x || y) || z) && p1)
	{
		cout << "YES" << endl;
		return 0;
	}
	if(d == false)
		d = x;
	if(c == false)
		c = y;
	if(b == false)
		b = z;
	cin >> x >> y >> z >> p2;
	if(((x || y) || z) && p2)
	{
		cout << "YES" << endl;
		return 0;
	}
	if(a == false)
		a = x;
	if(d == false)
		d = y;
	if(c == false)
		c = z;
	cin >> x >> y >> z >> p3;
	if(((x || y) || z) && p3)
	{
		cout << "YES" << endl;
		return 0;
	}
	if(b == false)
		b = x;
	if(a == false)
		a = y;
	if(d == false)
		d = z;
	cin >> x >> y >> z >> p4;
	if(((x || y) || z) && p4)
	{
		cout << "YES" << endl;
		return 0;
	}
	if(c == false)
		c = x;
	if(b == false)
		b = y;
	if(a == false)
		a = z;
	if((a && p1) || (b && p2) || (c && p3) || (d && p4))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}