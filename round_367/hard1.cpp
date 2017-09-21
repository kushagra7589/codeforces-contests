#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e5+10;
const long long INF = 1e16;

string reversal(string a)
{
	string y = "";
	for(int i=0; i<a.size(); ++i)
	{
		y = a[i] + y;
	}
	return y;
}

bool check(string a, string b)
{
	for(int i=0; i<min(a.size(), b.size()); ++i)
	{
		if(a[i] > b[i])
			return 1;
		if(a[i] < b[i])
			return 0;
	}
	return a.size() >= b.size();
}

vector<string> V;
long long cost[MAX_SIZE];
long long dp[MAX_SIZE][2];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>cost[i];
	for(int i=0; i<n; i++)
	{
		dp[i][0] = INF;
		dp[i][1] = INF;
	}
	dp[0][0] = 0;
	dp[0][1] = cost[0];
	string str;
	for(int i=0; i<n; i++)
	{
		cin>>str;
		V.push_back(str);
	}
	for(int i=1; i<n; i++)
	{
		if(check(V[i], V[i-1]) && dp[i-1][0] < dp[i][0])
			dp[i][0] = dp[i-1][0];
		if(check(V[i], reversal(V[i-1])) && dp[i-1][1] < dp[i][0])
			dp[i][0] = dp[i-1][1];
		if(check(reversal(V[i]), V[i-1]) && dp[i-1][0]  + cost[i] < dp[i][1])
			dp[i][1] = dp[i-1][0] + cost[i];
		if(check(reversal(V[i]), reversal(V[i-1])) && dp[i-1][1] + cost[i] < dp[i][1])
			dp[i][1] = dp[i-1][1] + cost[i];
	}
	if(dp[n-1][0] == INF && dp[n-1][1] == INF)
		cout<<-1<<endl;
	else
		cout<<min(dp[n-1][0], dp[n-1][1])<<endl;
	// for(int i=0; i<n; i++)
	// {
	// 	cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
	// }
	return 0;
}