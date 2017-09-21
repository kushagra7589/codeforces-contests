#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fast_cin() ios_base::sync_with_stdio(0)

typedef long long ll;
typedef long double ld;

vector<ll> arr;
vector<ll> prefix_sum;

ll solve(int l, int r)
{
	if(l == r)
		return 0;
	ld avg = ((ld)prefix_sum[r] + prefix_sum[l - 1])/2;
	auto high = upper_bound(prefix_sum.begin() + l, prefix_sum.begin() + r + 1, avg);
	int pos1 = high - prefix_sum.begin();
	int pos2 = pos1 - 1;
	// cout << pos2 << " " << endl;
	if(fabs(prefix_sum[pos2] - avg) <= fabs(prefix_sum[pos1] - avg))
	{
		if(pos2 >= l)
			return prefix_sum[r] - prefix_sum[l - 1] + solve(l, pos2) + solve(pos2 + 1, r);
		else
			return prefix_sum[r] - prefix_sum[l - 1] + solve(l, pos1) + solve(pos1 + 1, r);
	}
	else
	{
		return prefix_sum[r] - prefix_sum[l - 1] + solve(l, pos1) + solve(pos1 + 1, r); 
	}
}

int main()
{
	fast_cin();
	int t;
	cin >> t;
	int n;
	while(t--)
	{
		arr.clear();
		prefix_sum.clear();
		cin >> n;
		arr.resize(n + 1); prefix_sum.resize(n + 1);
		cin >> arr[1];
		prefix_sum[0] = 0;
		prefix_sum[1] = arr[1];
		for(int i = 2; i <= n; i++)
		{
			cin >> arr[i];
			prefix_sum[i] = prefix_sum[i - 1] +  arr[i];
		}
		ll a = solve(1, n);
		cout << a << endl;
	}
	return 0;
}	