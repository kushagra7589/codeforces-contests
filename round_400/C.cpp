#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define mp make_pair

unordered_map<ll, ll> hm;

vector<ll> arr;
vector<ll> prefix_sum;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	arr.resize(n);
	prefix_sum.resize(n);
	cin >> arr[0];
	prefix_sum[0] = arr[0];
	hm[prefix_sum[0]] = 1;
	ll cnt = 0;
	
	if(k == 1)
	{
		if(prefix_sum[0] == 1)
			cnt += 1;
	}
	else if(k == -1)
	{
		int x = 1;
		for(ll j=1; x <= 2; j*=k, x++)
		{
			if(prefix_sum[0] == j)
			{
				cnt += 1;
			}
		}
	}
	else
	{
		for(ll j=1; j<=1e14 && j>=(-1)*1e14; j*=k)
		{
			if(prefix_sum[0] == j)
				cnt += 1;
		}
	}
	for(int i=1; i<n; i++)
	{
		cin >> arr[i];
		prefix_sum[i] = prefix_sum[i-1] + arr[i];
		if(hm.find(prefix_sum[i]) == hm.end())
		{
			hm[prefix_sum[i]] = 0;
		}
		hm[prefix_sum[i]] += 1;
		
		if(k == 1)
		{
			if(prefix_sum[i] == 1)
				{
					cnt += 1;
				}
				if(hm.find(prefix_sum[i]-1) != hm.end())
				{
					cnt += hm[prefix_sum[i]-1];
				}
		}
		else if(k == -1)
		{
			int x = 1;
			for(ll j=1; x <= 2; j*=k, x++)
			{
				if(prefix_sum[i] == j)
				{
					cnt += 1;
				}
				if(hm.find(prefix_sum[i]-j) != hm.end())
				{
					cnt += hm[prefix_sum[i]-j];
				}
			}
		}
		else
		{
			for(ll j=1; j<=1e14 && j>=((ll)-1)*1e14; j*=k)
			{
				if(prefix_sum[i] == j)
				{
					cnt += 1;
				}
				if(hm.find(prefix_sum[i]-j) != hm.end())
				{
					cnt += hm[prefix_sum[i]-j];
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}