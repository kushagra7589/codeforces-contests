#include <bits/stdc++.h>

using namespace std;

vector<int> price;

int bsearch(int l, int h, int s)
{
	while(l < h)
	{
		int mid = l + (h-l)/2;
		if(price[mid] <= s)
		{
			l = mid + 1;
		}
		else
		{
			h = mid;
		}
	}
	return l-1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int x;
	price.push_back(0);
	for(int i=0; i<n; i++)
	{
		cin>>x;
		price.push_back(x);
	}
	int q;
	cin>>q;
	int m;
	sort(price.begin(), price.end());
	while(q--)
	{
		cin>>m;
		int ans = bsearch(1, n+1, m);
		cout<<ans<<endl;
	}
	return 0;
}