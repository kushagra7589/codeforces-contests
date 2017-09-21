#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define F first
#define S second

const int MAX_SIZE = 1e5+10;

vll arr(MAX_SIZE);

ll dp[MAX_SIZE][MAX_SIZE];

ll jack_max(int i, int n, int k, int j)
{
	for(int a=0; a<j; a++)
	{
		cout << "->";
	}
	cout << i << "|" << k;
	cout << endl;
	if(i > n)
		return 0L;
	if(i == n)
		return arr[n];
	if(i + k <= 0)
		return -1;
	if(dp[i][k] == -1)
	{
		if(k == 0)
			dp[i][k] = max(arr[i] + jack_max(i+2, n, 0, j+1), jack_max(i+1, n, k+1, j+1));
		else if(k > 0)
			dp[i][k] = max(arr[i] + jack_max(i+1, n, k-1, j+1), jack_max(i+1, n, k+1, j+1));
	}
	// dp[i] = max(arr[i] + (k == 0) ? jack_max(i+2, n, k) : jack_max(i+1, n, k+1), jack_max(i+1, n, k-1));
	// cout << endl;
	return dp[i][k];
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll sum = 0;
	memset(dp, -1L, MAX_SIZE*MAX_SIZE);
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	ll jack = jack_max(1, n, 0, 0);
	ll other = sum - jack;
	cout << jack << " " << other << endl;
	return 0;
}