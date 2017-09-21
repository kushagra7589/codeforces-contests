#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair

int K;
int N;
int total_amt;

int arr[100*100][100*100];

int capacity[101];
int amount[101];
int sorted_capacity[101];

int dp(int index, int k, int cumulative_cap, int amount_till_now	)
{
	if(index == N)
	{
		if(k < K)
			return 0;
		else if(cumulative_cap < total_amt)
			return 0;
		else
		{
			return amount_till_now;
		}
	}
	if(k == K)
	{
		if(cumulative_cap < total_amt)
			return 0;
		else
		{
			return amount_till_now;
		}
	}
	if(arr[cumulative_cap][amount_till_now] != -1)
		return arr[cumulative_cap][amount_till_now];

	arr[cumulative_cap][amount_till_now] = max(dp(index+1, k+1, cumulative_cap+capacity[index], amount_till_now + amount[index]), dp(index+1, k, cumulative_cap, amount_till_now));
	return arr[cumulative_cap][amount_till_now];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> N;
	total_amt = 0;
	for(int i=0; i<N; i++)
	{
		cin >> amount[i];
		total_amt += amount[i];
	}
	for(int i=0; i<N; i++)
	{
		cin >> capacity[i];
		sorted_capacity[i] = capacity[i];
	}
	sort(sorted_capacity, sorted_capacity+N);
	K = 0;
	ll cumulative_cap = 0;
	for(int i=N-1; i>=0; i--)
	{
		cumulative_cap += sorted_capacity[i];
		K++;
		if(cumulative_cap >= total_amt)
			break;
	}
	for(int i=0; i<100*100; i++)
	{
		for(int j=0; j<100*100; j++)
		{
			// for(int k = 0; k < K; k++)
				arr[i][j] = -1;
		}
	}
	ll ans = dp(0, 0, 0, 0);
	// cout << total_amt << endl;
	// cout <<  ans << endl;
	ans  = total_amt - ans;
	cout << K << " " << ans << endl;
}