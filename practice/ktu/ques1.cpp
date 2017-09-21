#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 1e3+10;

typedef long long ll;

unordered_map<string, set<string> > dict;

void change_order(string &a) 
{
	int arr[MAX_SIZE];
	for(int i=1; i<a.length()-1; i++)
	{
		arr[i] = a[i];
	}
	sort(arr+1, arr + a.length()-1);
	for(int i=1; i<a.length()-1; i++)
	{
		a[i] = arr[i];
	}
	// cout << a << endl;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int n, m;
	string input;
	string ans = "";
	for(int x=1; x<=t; x++)
	{
		cin >> n >> m;
		for(int i=0; i<n; i++)
		{
			cin >> input;
			string key = string(1, input[0]) + string(1, input[input.length()-1]);
			change_order(input);
			dict[key].insert(input);
		}
		for(int i=0; i<m; i++)
		{
			cin >> input;
			string key = string(1, input[0]) + string(1, input[input.length()-1]);
			if(dict.find(key) == dict.end())
			{
				ans += "0";
			}
			else
			{
				change_order(input);
				if(dict[key].find(input) == dict[key].end())
					ans += "0";
				else
					ans += "1";
			}
		}
		cout << "Case #" << x << ": " << ans << endl;
		dict.clear();
		ans = "";
	}
	return 0;
}