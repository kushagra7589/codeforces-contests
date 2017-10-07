#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x;
	string b, c;
	cin >> x >> b >> c;
	if(c == "week")
	{
		if(x == 5 || x == 6)
		{
			cout << 53;
		}
		else
		{
			cout << 52;
		}
	}
	else if(c == "month")
	{
		if(x <= 29)
		{
			cout << 12;
		}
		else if(x == 30)
		{
			cout << 11;
		}
		else
		{
			cout << 7;
		}
	}
	return 0;
}