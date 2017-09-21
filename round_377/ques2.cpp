#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 510;

int arr[MAX_SIZE][MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i][0];
	}
	int min_sum = 1e7+20;
	int minim = 1;
	int sum = 0;
	int temp = 1;
	for(int i=0; i<=k; i++)
	{
		sum = i;
		arr[0][temp] = arr[0][0] + i;
		for(int j=1; j<n; j++)
		{
			sum += max(k - arr[j][0] - arr[j-1][temp], 0);
			arr[j][temp] = arr[j][0] + max(k - arr[j][0] - arr[j-1][temp], 0);
		}
		// min_sum = min(min_sum, sum);
		if(sum <  min_sum)
		{
			minim = temp;
			min_sum = sum;
		}
		temp++;
	}
	cout << min_sum << endl;
	for(int i=0; i<n; i++)
	{
		cout << arr[i][minim] << " ";
	}
	cout << endl;
}	