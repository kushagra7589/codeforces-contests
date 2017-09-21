#include <bits/stdc++.h>

using namespace std;

#define fast_io() ios_base::sync_with_stdio(false)

typedef long long ll;

#define mp make_pair
#define pb push_back
#define F first
#define S second

int main()
{
	int a, b;
	cin >> a >> b;
	int v1 = 0;
	int v2  = 0;
	for(int i = 1; ; i+=2)
	{
		a -= i;
		if(a < 0)
			break;
		v1++;
	}
	for(int i = 2; ;i+=2)
	{
		b-=i;
		if(b < 0)
			break;
		v2++;
	}
	if(v1 > v2)
	{
		cout << "Valera" << endl;
	}
	else
	{
		cout << "Vladik" << endl;
	}
	return 0;
}