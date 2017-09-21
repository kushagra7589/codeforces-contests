#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define F first
#define S second

vector<ll> arr;

int main()
{
	ios_base::sync_with_stdio(false);
	ll n, t, d, k;
	cin >> n >> t >> k >> d;
	arr.resize(1000001);
	for(int i = 0; i <= 1000000; i++)
	{
		arr[i] = 0;
	}
	for(int i = t; i <= 1000000; i += t)
	{
		arr[i] = k;
	}
	ll sum = 0;
	int count1  = 0;
	for(int i = 1; i <= 1000000; i++)
	{
		count1 += 1;
		sum += arr[i];
		if(sum >= n)
			break;
	}
	// cout << "count1 = " << count1 << endl;
	for(int i = d + t; i <= 1000000; i +=t )
	{
		arr[i] += k;
	}
	sum = 0;
	int count2 = 0;
	for(int i = 1; i <= 1000000; i++)
	{
		count2 += 1;
		sum += arr[i];
		if(sum >= n)
			break;
	}
	// cout << "count2 = " << count2 << endl;
	if(count2 < count1)
		cout << "YES";
	else
		cout << "NO";
	cout << endl;
	return 0;
}