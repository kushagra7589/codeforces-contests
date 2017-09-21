#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

const int MAX_SIZE = 1e5+10; 

ll arr[MAX_SIZE];
ll reqd[MAX_SIZE];

int max1(int a, int b)
{
	return (a>b)?a:b;
}

bool checkPossible(int x, int m)
{
	ll used = 0;
	bool done[m+1];
	for(int i=1; i<=m; i++)
		done[i] = false;
	for(int i=x; i>=0; i--)
	{
		if(arr[i] != 0)
		{
			if(done[arr[i]] == false)
			{
				if(used + reqd[arr[i]] < i)
				{
					done[arr[i]] = true;
					used += reqd[arr[i]];
				}
				else
				{
					used = max1(0, used - 1);
				}
			}
			else
			{
				used = max1(0, used - 1);
			}
		}
		else
		{
			used = max1(0, used - 1);
		}
	}
	for(int i=1; i<=m; i++)
	{
		if(done[i] == false)
			return false;
	}
	return true;
}

int binarySearch(int l, int h, int m)
{
	while(l < h)
	{
		int mid = (l+h)/2;
		// bool check = checkPossible(mid, m);
		// cout << mid << " : " <<  check << endl;
		// cout << "l = " << l << " h = " << h << endl;
		if(checkPossible(mid, m) == true)
		{
			h = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	return l;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
	}
	for(int i=1; i<=m; i++)
	{
		cin >> reqd[i];
	}
	int ans  = binarySearch(1, n+1, m);
	if(ans == n+1)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
}	