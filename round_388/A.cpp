#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pll pair<ll>
#define mp make_pair
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if(n % 2 == 0)
	{
		cout << n / 2 << endl;
		for(int i=0; i<n/2; i++)
			cout << 2 << " ";
		cout << endl;
	}
	else
	{
		int ans = 1;
		n = n - 3;
		ans += n/2;
		cout << ans << endl;
		for(int i=0; i<n/2; i++)
		{
			cout << 2 << " ";
		}
		cout << 3 << endl;
	}
	return 0;
}