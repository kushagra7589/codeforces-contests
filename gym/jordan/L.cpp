#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define F first
#define S second

ll N[20], M[20], sn[1000], sm[1000], in = 0, im = 0;
map<ll, ll> SUM1, SUM2;


void make_sum(ll arr[], int n, int i, int curr)
{
	if(i == n){
		if(SUM1.find(curr) == SUM1.end())
			SUM1[curr] = 0;
		SUM1[curr] += 1;
		return;
	}
	make_sum(arr, n, i + 1, curr);
	make_sum(arr, n, i + 1, curr + arr[i]);
}

void check_sum(ll arr[], int n, int i, int curr)
{
	if(i == n){
		if(SUM2.find(curr) == SUM2.end())
			SUM2[curr] = 0;
		SUM2[curr] += 1;
		return;
	}
	check_sum(arr, n, i + 1, curr);
	check_sum(arr, n, i + 1, curr + arr[i]);
}

int main()
{
	int n, m;
	cin >> n >> m;
	ll sum = 0;
	ll red[20], blue[20];
	for(int i = 0; i < n; i++)
	{
		cin >> red[i];
	}
	for(int i = 0; i < m; i++)
	{
		cin >> blue[i];
	}
	make_sum(red, n, 0, 0);
	// for(auto &i: SUM)
	// 	cout << i << " ";
	// cout << endl;
	check_sum(blue, m, 0, 0) ;
	ll ans = 0;
	SUM1[0] = 0;
	SUM2[0] = 0;
	for(auto &i: SUM1)
	{
		if(SUM2.find(i.F) != SUM2.end())
		{
			ans += SUM2[i.F] * i.S;
		}
	}
	// SUM.clear();
	// make_sum(blue, m, 0, 0);
	// ans *= (check_sum(red, n, 0, 0) - 1);
	cout << ans << endl;
	return 0;
}