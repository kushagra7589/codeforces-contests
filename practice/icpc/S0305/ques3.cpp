#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 101;

multiset< ll > ans;
vector< mutliset < ll > > A(MAX_SIZE);

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int m, k;
		cin >> m >> k;
		int n;
		ll x;
		for(int i=0; i<m; i++)
		{
			cin >> n;
			for(int j=0; j<n; j++)
			{
				cin >> x;
				A[i].insert(x);
			}
		}
	}
	return 0;
}