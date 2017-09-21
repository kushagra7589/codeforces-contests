#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	if(n == 1)
		cout << "-1" << endl;
	else
		cout << n << " " << n + 1 << " " << n * (n+1) << endl;  
	return 0;
}