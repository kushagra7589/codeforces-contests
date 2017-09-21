#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e5+10;

int arr[MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
	}
	int dis;
	dis = abs(arr[1] - arr[n]);
	if(n == 1)
		cout << 0 << endl;
	else if(n == 2)
	{
		if(k < dis)
			cout << dis - k <<  endl;
		else
			cout << (k-dis)%2 << endl;
	}
	else
	{
		cout << max(dis-k, 0) << endl;
	}
}