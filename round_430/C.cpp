#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first
#define S second

typedef long long ll;

const int MAX_SIZE = 3e5 + 10;

bool arr[MAX_SIZE];

int main()
{
	int n, m;
	cin >> n >> m;
	int a;
	memset(arr, false, sizeof(arr));
	for(int i = 0; i < n; i++)
	{
		cin >> a;
		arr[a] = true;
	}
	ll x;
	while(m--)
	{
		cin >> x;
		ll l = 0; h = 4 * MAX_SIZE;
		while(l < h)
		{
			ll mid = (l + h)/2;
		}
	}
	return 0;
}