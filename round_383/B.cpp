#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair< ll >
#define vll vector<ll>
#define mp make_pair
#define pb push_back
#define F first
#define S second

// multiset<int> input;
const int MAX_SIZE = 1e7+10;
int arr[MAX_SIZE] = {0};
int input[MAX_SIZE];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, x;
	cin >> n >> x;
	int a;

	for(int i=0; i<n; i++)
	{
		cin >> a;
		input[i] = a;
		arr[a] += 1;
	}
	int count = 0;
	for(int i=0; i<n; i++)
	{
		int y = input[i]^x;
		if(y != input[i])
			count += arr[y];
		else
			count += arr[y]-1;
	}
	cout << count/2 << endl; 
	return 0;
}