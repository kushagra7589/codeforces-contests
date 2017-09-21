#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7;

const int N = 3e5 + 10;

ll pow2[N];

int main()
{
	pow2[0] = 1;
	for(int i = 1; i < N; i++)
	{
		pow2[i] = (2 * pow2[i - 1]) % M;
	}
	int n;
	cin >> n;
	ll arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	ll ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans = (ans + pow2[i]*arr[i]) % M;
		ans = (ans - pow2[n - 1 - i]*arr[i] + M) % M;
	}
	cout << ans << endl;
}