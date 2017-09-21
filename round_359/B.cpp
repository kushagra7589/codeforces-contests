#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

void swap(ll &a, ll &b)
{
	ll temp = a;
	a = b;
	b= temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<ll> inp(n);
	for(int i=0; i<n; i++)
	{
		cin >> inp[i];
	}	
	for(int i=0; i<n-1; i++)
	{
		for(int j = 0; j < n-1-i; j++)
		{
			if(inp[j] > inp[j+1])
			{
				swap(inp[j], inp	 [j+1]);
				cout << j+1 << " " << j + 2 <<  endl;
			}
		}
	}
	return 0;
}