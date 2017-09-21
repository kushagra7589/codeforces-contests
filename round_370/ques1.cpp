#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 1e5+10;

int arr[MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
	}
	arr[n+1] = 0;
	for(int i=1; i<=n; i++)
	{
		cout << arr[i] + arr[i+1] << " ";
	}
	cout << endl;
	return 0;
}