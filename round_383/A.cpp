#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair< ll >
#define vll vector<ll>
#define mp make_pair
#define pb push_back
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if(n == 0)
		{
			cout << 1 << endl;
			return 0;
		}
	int ans = (n-1)%4;
	if(ans == 0)
		cout << 8 ;
	else if (ans == 1)
		cout << 4;
	else if(ans == 2)
		cout << 2;
	else if(ans == 3)
		cout << 6;
	cout << endl;
	return 0;
}