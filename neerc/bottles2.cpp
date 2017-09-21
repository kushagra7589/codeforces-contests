#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 100;

vector< pii > bottles;
int N;
int K;
int total_amt;

int arr[MAX_SIZE][MAX_SIZE*MAX_SIZE][MAX_SIZE];

int dp(int i, int k, int cap, int amt)
{
	if(i == N)
	{
		if(k < K)
			return 0;
		else if(cap < total_amt)
			return 0;
		else
			return amt;
	}
	if(k == K)
	{
		if(cap < total_amt)
			return 0;
		else
			return amt;
	}

	if(arr[i][cap][k] != -1)
		return arr[i][cap][k];

	arr[i][cap][k] = max(dp(i+1, k+1, cap+bottles[i].F, amt+bottles[i].S), dp(i+1, k, cap, amt));

	return arr[i][cap][k];
}

struct sort_pred_des {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second  < right.second;
    }
};

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	N = n;
	bottles.resize(n);
	total_amt = 0;
	for(int i=0; i<n; i++)
	{
		cin >> bottles[i].S;
		total_amt += bottles[i].S;
	}
	for(int i=0; i<n; i++)
	{
		cin >> bottles[i].F;
	}

	sort(bottles.begin(), bottles.end());

	int cumulative_cap = 0;
	K = 0;
	for(int i=n-1; i>=0; i--)
	{
		cumulative_cap += bottles[i].F;
		K++;
		if(cumulative_cap >= total_amt)
			break;
	}
	for(int i=0; i<MAX_SIZE;i++)
	{
		for(int j=0; j<MAX_SIZE*MAX_SIZE; j++)
		{
			for(int k = 0; k < MAX_SIZE; k++)
			{
				arr[i][j][k] = -1;
			}
		}
	}

	sort(bottles.begin(), bottles.end(), sort_pred_des());
	int ans = dp(0, 0, 0, 0);
	ans  = total_amt - ans;
	cout << K << " " << ans << endl;
	return 0;
}