#include <bits/stdc++.h>

using namespace std;

int arr[110];
bool flag[110];

int main()
{
	int n;
	cin >> n;
	memset(flag, false, sizeof(flag));
	for(int i = 1; i <= 2*n; i++)
	{
		cin >> arr[i];
	}
	long long ans = 0;
	for(int k = 0; k < n - 1; k++)
	{
		int M = 1e7;
		int x = 109;
		int y = 109;
		for(int i = 1; i <= 2*n; i++)
		{
			if(flag[i] == false)
			{
				for(int j = 1; j <= 2*n; j++)
				{
					if(i != j && flag[j] == false)
					{
						if(abs(arr[j] - arr[i]) < M)
						{
							M = abs(arr[j] - arr[i]);
							x = i;
							y = j;
						}
					}
				}
			}
		}
		// cout << M << " " << x << " " << y << endl;
		flag[x] = true;
		flag[y] = true;
		ans += M;
	}
	cout << ans << endl;
	return 0;
}