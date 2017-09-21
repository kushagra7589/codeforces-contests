#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back

const int MAX_SIZE = 1e5+10;
const int M = 1e9+7;

vll X(MAX_SIZE);
vll initial(MAX_SIZE);
vll f(MAX_SIZE);
int main()
{
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n >> q;
	ll a, b;
	cin >> f[1] >> f[2];
	cin >> a >> b;
	for(int i=0; i<MAX_SIZE; i++)
	{
		X[i] = 0;
	}
	for(int i=3; i<=n; i++)
	{
		f[i] = ((b*f[i-1])%M + (a*f[i-2])%M)%M;
	}
	for(int i=1; i<=n; i++)
	{
		X[i] = 0;
		cin >> initial[i];
	}
	// int q;
	// cin >> q;
	int l, r;
	while(q--)
	{
		cin >> l >> r;
		X[l] = (X[l] + f[1])%M;
		X[l+1] = (X[l+1] + f[2])%M;
		X[r+1] = (X[r+1] - f[r-l+2] + M)%M;
		X[r+2] = (X[r+2] - f[r-l+3] + M)%M;
	}
	for(int i=1; i<=n; i++)
	{
		cout << X[i] << " ";
	}
	cout << endl;
	for(int i=3; i<=n; i++)
	{
		X[i] = (X[i] + (b*X[i-1])%M + (a*X[i-2])%M)%M;
	}
	for(int i=1; i<=n; i++)
	{
		X[i] = (X[i] + initial[i])%M; 
		cout << X[i] << " ";
	}
	cout << endl;
	return 0;
}