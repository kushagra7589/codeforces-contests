#include <bits/stdc++.h>

using namespace std;

set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

int main()
{
	string a;
	cin >> a;
	int n = a.length();
	a += "aaaaaa";
	for(int i = 0; i < n;)
	{
		int cnt = 0;
		for(int j = 0; j < 3; j++)
		{
			if(vowels.find(a[i + j]) == vowels.end())
			{
				cnt++;
			}
		}
		if(cnt < 3)
		{
			cout << a[i];
			i += 1;
		}
		else
		{
			if(a[i] == a[i + 1] && a[i + 1] == a[i + 2])
			{
				cout << a[i];
				i+=1;
			}
			else
			{
				cout << a[i] << a[i + 1] << " ";
				i += 2;
			}
		}
	}
	return 0;
}