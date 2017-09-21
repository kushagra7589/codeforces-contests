	#include <bits/stdc++.h>

	using namespace std;

	const int MAX_SIZE = 1e5+10;

	int arr[MAX_SIZE];
	int main()
	{
		int n;
		cin >> n;
		int mini = 1e9+1;
		int maxi = -1;
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
			mini = min(arr[i], mini);
			maxi = max(arr[i], maxi);
		}
		int cnt = 0;
		for(int i=0; i<n; i++)
		{
			if(arr[i] != mini && arr[i] != maxi)
				cnt++;
		}
		cout << cnt << endl;
		return 0;
	}