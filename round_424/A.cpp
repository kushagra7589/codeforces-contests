#include <bits/stdc++.h>

using namespace std;

int arr[110];

int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	bool inc = true, con = 0, dec = 0;
	int i = 0; 
	while(arr[i] < arr[i + 1] && i < n - 1)
	{
		i++;
	}
	while(arr[i] == arr[i + 1] && i < n - 1)
		i++;
	while(arr[i] > arr[i + 1] && i < n - 1)
	{
		i++;
	}
	if(i == n - 1)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
	return 0;
}