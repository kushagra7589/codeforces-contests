#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

map<char, char> swap1;

int main()
{
	ios_base::sync_with_stdio(false);
	string pattern;
	string actual;
	cin >> pattern >> actual;
	int flag = 1;
	for(int i=0; i<pattern.length(); i++)
	{
		if(swap1.find(pattern[i]) == swap1.end())
		{
			swap1[pattern[i]] = actual[i];
		}
		if(swap1.find(actual[i]) == swap1.end())
		{
			swap1[actual[i]] = pattern[i];
		}
		if(swap1[pattern[i]] != actual[i])
		{
			flag = 0;
			break;
		}
		if(swap1[actual[i]] != pattern[i])
		{
			flag = 0;
			break;
		}
	}
	if(flag)
	{

		map<char, char> ans;
		for(auto it : swap1)
		{
			if(ans.find(it.F) == ans.end() && ans.find(it.S) == ans.end() && it.F != it.S)
			{
				ans[it.F] = it.S;
			}
		}
		cout << ans.size();
		cout << endl;
		for(auto it : ans)
		{
			cout << it.F << " " << it.S << endl;
		}
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}