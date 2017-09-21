#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second

set<string> pol, ene, common;

int main()
{
	string S;
	ll n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++)
	{
		cin >> S;
		pol.insert(S);
	}
	for(int i=0; i<m; i++)
	{
		cin >> S;
		if(pol.find(S) != pol.end())
		{
			pol.erase(S);
			common.insert(S);	
		}
		else
		{
			ene.insert(S);
		}
	}
	if(pol.size() + common.size() - common.size()/2 > ene.size() + common.size()/2)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}