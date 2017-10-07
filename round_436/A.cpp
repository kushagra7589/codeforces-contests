#include <bits/stdc++.h>

using namespace std;;

typedef long long ll;

#define pb push_back
#define F first
#define S second

set<int> A[210];

int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int i = 0;
	// int n = s.length();
	int j = 0;
	while(i < n)
	{
		if(s[i] < 97)
		{
			i++;
			j++;
			continue;
		}
		A[j].insert(s[i]);
		i++;
	}
	int m = 0;
	for(i = 0; i < 210; i++)
	{
		m = max(m, (int)A[i].size());
	}
	cout << m << endl;
	return 0;
}