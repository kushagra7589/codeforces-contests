#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long a, b;
	long long mul ;
	int x = 0;
	cin >> a >> b;
	while(a <= b)
	{
		a = a*3;
		b = b*2;
		x += 1;
	}
	cout << x << endl;
	return 0;
}