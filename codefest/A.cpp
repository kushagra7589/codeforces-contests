#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

const int MAX_SIZE = 1e5 + 10;

set<string> A;

int main()
{
	int n;
	cin >> n;
	string s;
	for(int i = 0; i < n; i++)
	{
		cin >> s;
		if(A.find(s) == A.end())
		{
			cout << "NO" << endl;
			A.insert(s);
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	return 0;
}