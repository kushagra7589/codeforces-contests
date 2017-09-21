#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_SIZE = 1e5+10;

int arr[MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	int n, c;
	cin >> n >>c;
	int count = 0;
	cin >> arr[1];
	count = 1;
	for(int i=2; i<=n; i++)
	{
		cin >> arr[i];
		if(arr[i] - arr[i-1] <= c)
		{
			count += 1;
		}
		else
		{
			count = 1;
		}
	}
	cout << count << endl;
	return 0;
}