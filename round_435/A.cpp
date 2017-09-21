#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define F first
#define S second

set<int> A;

int main()
{
	int n, x;
	cin >> n >> x;
	int k;
	for(int i = 0; i < n; i++)
	{
		cin >> k;
		A.insert(k);
	}
	int cnt = 0;
	for(int i = 0; i < x; i++)
	{
		if(A.find(i) == A.end())
		{
			cnt++;
		}
	}
	if(A.find(x) != A.end())
	{
		cnt++;
	}
	cout << cnt;
	return 0;
}