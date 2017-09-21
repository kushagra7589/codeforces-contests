#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define sll set<ll>
#define msll multiset<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 1e5;
const int M  = 1e9+7;

vll Y;

bool is_possible(ll minmax, int n)
{
	if(minmax > Y[n-1])
		return true;
	if(minmax*2 + 1 < Y[n-1])
		return false;
	if(minmax*2 + 1 == Y[n-1])
	{
		if(Y[n-2] == minmax*2)
			return false;
	}
	sll solution;
	for(int i = n-1; Y[i] >= minmax/2; i--)
	{
		if(solution.find(Y[i]/2) != solution.end())
			return false;
		else
		{
			solution.insert(Y[i]/2);
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll input;
	for(int i=0; i<n; i++)
	{
		cin >> input;
		Y.pb(input);
	}
	sort(Y.begin(), Y.end());
	ll l = 1;
	ll u = Y[n-1];
	while(l < u)
	{
		ll mid = (l + u)/2;
		if(is_possible(mid, n))
		{
			l = mid + 1;
		}
		else
		{
			u = mid;
		}
	}
	ll res = l-1;
	sll solution;
	if(Y[0] == 1)
		solution.insert(1);
	for(int i=n-1; i>=0; i--)
	{
		if(Y[i] == 1)
			continue;
		if(solution.find(Y[i]/2) != solution.end())
		{
			solution.insert(Y[i]);
		}
		else
			solution.insert(Y[i]/2);
	}
	for(auto x : solution)
		cout << x << " ";
	cout << endl;
	return 0;
}