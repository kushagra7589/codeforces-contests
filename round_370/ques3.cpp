#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int x, y;
	cin >> x >> y;
	int arr[3] = {y, y, y};
	int counter = 0;
	while(arr[0] != x)
	{
		int temp1 = arr[1];
		int temp2 = arr[2];
		arr[0] = temp1;
		arr[1] = temp2;
		arr[2] = min(x, arr[0] + arr[1] - 1);
		counter++;
		// cout << arr[0] << " " << arr[1] << " " << arr[2] << endl;
	}
	cout << counter << endl;
	return 0;
}