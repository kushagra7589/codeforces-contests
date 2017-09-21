#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define F first
#define S second

string usernames[110];
string put[110];
set<string> S;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		for(int i=1; i<n; i++)
			cin >> usernames[i];
		int m;
		cin >> m;
		int i = 0;
		string prev = "";
		while(i < m)
		{
			cin >> word;
			if(word[word.length() - 1] == ':')
			{
				i++;
				S.clear();
				for(auto it : usernames)
				{
					S.insert(it);
				}
			}
		}
	}
	return 0;
}