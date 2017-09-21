#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair< ll >
#define vll vector<ll>
#define mp make_pair
#define pb push_back
#define F first
#define S second

const int MAX_SIZE = 110;

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
	int flag = 0;
	for(int t=1; t<=200; t++)
	{
		for(int j=1; j<=n; j++)
		{
			int x = j;
			int i = 0;
			while(i < t)
			{
				x = arr[x];
				i++;
			}
			i = 0;
			while(i < t)
			{
				x = arr[x];
				i++;
			}
			if(x != j)
			{
				flag  = 0;
				break;
			}
			else
			{
				flag  = 1;
			}
		}
		if(flag == 1)
		{
			cout << t << endl;
			return 0; 
		}
	}
	cout << -1 << endl;
	return 0;
}