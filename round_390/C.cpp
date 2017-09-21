#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define F first
#define S second

int arr[10000];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int flag = 0;
	int sum = 0;
	int k, l, r;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
		if(flag == 0 && arr[i] != 0)
			flag = 1;
		sum += arr[i];
	}	
	if(flag)
	{
		cout << "YES" << endl;
		if(sum != 0)
		{
			cout << 1 << endl << 1 << " " << n << endl;
		}
		else
		{
			k = 2;
			int l1 = 1;
			int r1 = 0;
			while(r1 < n && arr[r1] == 0)
			{
				r1++;
			}
			r1 += 1;
			cout << 2 << endl << 1 << " " << r1 << endl << r1 + 1 << " " << n << endl;
		}
	}
	else
		cout  << "NO" << endl;
	return 0;
}