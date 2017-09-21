#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;

int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main() 
{
	int n;
	cin >> n;
	int a = (n - 1) / 2;
	int b;
	for(int i = a; i >= 1; i--)
	{
		if(gcd(a, n - a) == 1)
		{
			cout << a << " " << n - a;
			return 0;
		}
		a--;
	}
	return 0;
}