#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define F first 
#define S second
typedef long long ll;

const int MAX_SIZE = 1e5 + 10;

int arr[MAX_SIZE];

int main()
{
	int t;
	cin >> t;
	int n;
	string s;
	while(t--)
	{
		for(int i = 0; i < MAX_SIZE; i++)
			arr[i] = 0;
		cin >> n;
		int x;
		for(int i = 0; i < n; i++)
		{
			cin >> s >> x;
			arr[x] += 1;
		}
		int M = 0;
		int ans = 0;
		for(int i = 0; i < MAX_SIZE; i++)
		{
			if(arr[i] > M)
			{
				M = arr[i];
				ans = i;
			}
		}
		cout << ans << endl;
	}
	return 0;
}