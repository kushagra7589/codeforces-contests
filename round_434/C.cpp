#include <bits/stdc++.h>

using namespace std;

set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

int main()
{
	string a;
	cin >> a;
	set<string> con;
	string s = "";
	for(int i = 0;  i < a.length(); i++)
	{
		if(vowels.find(a[i]) == vowels.end)
		{
			s.pb(a[i]);
		}
		else
		{
			if(s.length > 0)
				con.insert(s);
			s = "";
		}
	}
	for(auto &i : con)
	{
		int j = 0;
		int len;
		while(j < i.length())
		{
			char a = i[j];
			int len = 0;
			while(i[j] == a)
			{
				j++;
				len++;
			}
			if(len > 3)
			{
				len++;
			}
		}
	}
	return 0;
}