#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define S second

int arr[500];

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int max_ele = -1;
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
		max_ele = max(max_ele, arr[i]);
	}
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		sum += max_ele - arr[i];
	}
	cout << sum << endl;
	return 0;
}