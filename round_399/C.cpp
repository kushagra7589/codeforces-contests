#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

const int MAX_SIZE =  1024;

pair<int, int> arr[MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	for(int i=0; i<MAX_SIZE; i++)
		arr[i].F = arr[i].S = 0;
	int n, k, x;
	cin >> n >> k >> x;
	int a;
	for(int i=0; i<n; i++)
	{
		cin >> a;
		arr[a].F += 1;
		arr[a].S = arr[a].F;
	}
	// for(int i=0; i<MAX_SIZE; i++)
	// {
	// 	if(arr[i].F > 0)
	// 		cout << i << " ";
	// }
	// cout << endl;
	while(k--)
	{
		int sum = 0;
		int factor;
		for(int i=0; i<MAX_SIZE; i++)
		{
			int add = arr[i].S;
			if(arr[i].S > 0)
			{
				if(sum & 1)
					factor = arr[i].S/2;
				else
					factor = (arr[i].S+1)/2;
				// cout << "Working on :" << i << endl;
				// cout << "Current index :" << sum << endl;
				// cout << "After xor : " << (i^x) << endl;
				// cout << "Factor : " << factor << endl;
				// cout << "-----------------" << endl;
				arr[i].F -= factor;
				arr[(i^x)].F += factor;
			}			
			sum += add;
		}
		for(int i=0; i<MAX_SIZE; i++)
		{
			arr[i].S = arr[i].F;
		}
		// for(int i=0; i<MAX_SIZE; i++)
		// {
		// 	if(arr[i].F > 0)
		// 		cout << i << " ";
		// }
		// cout << endl;
	}
	for(int i=MAX_SIZE-1; i>=0; i--)
	{
		if(arr[i].F > 0)
		{
			cout << i << " ";
			break;
		}
	}
	for(int i=0; i<MAX_SIZE; i++)
	{
		if(arr[i].F > 0)
		{
			cout << i;
			return 0;
		}

	}
	return 0;
}