#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 3e5+10;

int arr[MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i=1; i<=n; i++)
		cin >> arr[i];
	sort(arr+1, arr+n+1);
	int median = (n+1)/2;
	cout << arr[median] << endl;
	return 0;
}