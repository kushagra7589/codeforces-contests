#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e6+10;

int arr[MAX_SIZE];

int main()
{
	int n;
	cin >> n;
	for(int i=0; i<n; i++)
		cin >> arr[i];
	if(n == 1)
	{
		cout << "NO" << endl;
		return 0;
	}
	long long X = 0;
	for(int i=0; i<n; i++)
	{
		int sum = 0;
		int j;
		for(j=1; sum+j<=arr[i]; j++)
			sum += j;
		// cout << arr[i] << " " ;
		// cout << j-1 << endl;
		X = X ^ ((long long)j - 1);
	}
	if(X == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}