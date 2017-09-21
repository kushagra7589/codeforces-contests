#include <bits/stdc++.h>

using namespace std;

int a[10010] = {0};
int main()
{
	int n, x;
	cin >> n >> x;
	for(int i=0; i<n; i++)
	{
		int q;
		cin >> q;
		a[q]++;
	}
	long long int c = 0;
	for(int i=0; i<=100000; i++)
	{
		int q = i^x;
		if(q <= 100000 && a[i] != 0)
		{
			if(q > i)
			{
				c += a[q]*a[i];
			}
			else if(q == i)
			{
				long long qw = a[q];
				c += ((qw)*(qw-1)/2);
			}
		}
	}
	cout << c << endl;
}