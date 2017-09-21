#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define F first
#define S second

int mod(int a, int m)
{
	return (a + m) % m;
}

int fifreqd(int a)
{
	return ((a+49)/50);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int p, x, y;
	cin >> p >> x >> y;
	int reqd;
	int mini = 1e7;
	p = mod(p - 26, 475);
	for(int i = 0; i < 25; i++)
	{
		// reqd = mod(mod(p - 68, 475) * 381, 475) * 50;
		// cout << p;
		p = mod(mod(p - 42, 475) * 381, 475);
		reqd = p * 50;
		// cout << "reqd = " << reqd << endl;
		if(reqd + 49 >= y)
		{
			if(fifreqd(reqd + 49 - x) != fifreqd(y - x))
			{
				mini = min(mini, max(0, (reqd-x+99)/100));
				// cout << "chose for mini " << (reqd - x + 99)/100 << endl;
			}
		}
	}
	cout << mini << endl;
	return 0;
}