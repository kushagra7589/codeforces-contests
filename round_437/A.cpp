#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define F first
#define S second
#define fast_cin() ios_base::sync_with_stdio(false)


int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	if(s[0] == 'S' && s[n - 1] == 'F')
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}