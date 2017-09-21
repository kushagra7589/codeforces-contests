#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e5+10;

typedef long long ll;

ll arr[MAX_SIZE];

int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll a[3];
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
	}
	sort(arr+1, arr+n+1);
	int diff = 1;
	ll check = arr[1];
	a[0] = check;
	int flag  = 0;
	int i = 1;
	int counter = 1;
	for(int i=2; i<=n; i++)
	{
		if(arr[i] != check)
		{
			check = arr[i];
			diff++;
			a[counter++] = check;
		}
		if(diff > 3)
		{
			flag = 1;
			break;
		}
	}
	if(flag)
	{
		cout << "NO" << endl;
	}
	else
	{
		// if(diff == 3)
		// {
		// 	cout << "YES" << endl;
		// }
		// else if(diff == 2)
		// {
		// 	if((arr[n] - arr[1])%2 == 0)
		// 	{
		// 		cout << "YES" << endl;
		// 	}
		// 	else
		// 	{
		// 		cout << "NO" << endl;
		// 	}
		// }
		// else if(diff == 1)
		// {
		// 	cout << "NO" << endl;
		// }
		if(diff == 3)
		{
			if(a[2] - a[1] == a[1] - a[0])
				cout << "YES" <<  endl;
			else
				cout << "NO" << endl;
		}
		else if(diff == 2)
		{
			if((a[1] - a[0]) % 2 == 0)
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl; 
			}
		}
		else
		{
			cout << "YES" << endl; 
		}

	}
	return 0;
}