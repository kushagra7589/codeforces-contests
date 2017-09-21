#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

const int MAX_SIZE = 1e5+10;

ll checkatPos(int x, int n, int d)
{
	if(n%2)
	{
		if(x%2)
		{
			return (x+n)%d;
		}
		else
		{
			return (x-n+d)%d;
		}
	}
	else
	{
		if(x%2)
		{
			return (x-n+d)%d;
		}
		else
		{
			return (x+n)%d;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll d, k, n;
	ll p;
	cin >> d >> k >> n;
	n = (n%d);	
	if(k % 2)
		p = (k+n)%d;
	else
		p = (k-n+d)%d;
	p = p==0?d:p;
	ll pos1 = (p+1)%d;
	ll pos2 = (p-1+d)%d;
	pos1 = pos1==0?d:pos1;
	pos2 = pos2==0?d:pos2;
	ll a = checkatPos(pos1, n, d);
	ll b = checkatPos(pos2, n, d);
	a = a==0?d:a;
	b = b==0?d:b;
	cout << a << " " << b << endl;
	return 0;
}		