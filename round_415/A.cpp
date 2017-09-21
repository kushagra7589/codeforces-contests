#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	int n, k, sum = 0;
	cin >> n >> k;
	int x;
	for(int i = 0; i < n; i++) 
	{
		cin >> x;
		sum += x;
	}
	long double N = n, K = k, S = sum;

	cout << max((long double)0, ceil (2*(N*K - 0.5*N - S))) << endl; 

	return 0;
}