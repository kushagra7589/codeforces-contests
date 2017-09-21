#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>

const int M = 1e9+7;
const int MAX_SIZE = 1e5+10;

int arr[MAX_SIZE];
unordered_map<int, int> count1;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	int ans = -1;
	cin >>  n;
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
		if(count1.find(arr[i]) == count1.end())
		{
			count1[arr[i]] = 0;
		}
		count1[arr[i]] += 1;
		if(count1[arr[i]] == n)
			ans = 0;
	}
	int m;
	cin >> m;
	int index, color;
	for(int i=1; i<=m; i++)
	{
		cin >> index >> color;
		count1[arr[index]] -= 1;
		arr[index] = color;
		if(count1.find(color) == count1.end())
		{
			count1[color] = 0;
		}
		count1[color] += 1;
		if(ans == -1 && count1[color] == n)
			ans = i;
	}
	cout << ans << endl;
	return 0;
}