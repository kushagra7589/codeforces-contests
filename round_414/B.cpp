#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define F first
#define S second

int main()
{
	// ios_base::sync_with_stdio(false);
	ld n, h;
	cin >> n >> h;
	for(int i = 1; i < n; i++)
	{
		ld x = i;
		printf("%.8Lf ", h * (sqrt(x/n)));
	}	
	cout << endl;
	return 0;
}