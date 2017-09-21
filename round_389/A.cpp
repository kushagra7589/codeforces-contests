#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m, k;
	cin >> n >> m >> k;
	int l, r, d1, d2;
	l = (k + 2*m - 1)/(2*m);
	r = ((k % (2*m)) == 0) ? 2*m : (k % (2*m));
	r = (r+1)/2;
	cout << l << " " << r << " ";
	(k % 2) ? cout << "L" : cout << "R";
	cout << endl;
	return 0;
}