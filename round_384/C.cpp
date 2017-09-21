#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	int n, a, b;
	cin >> n >> a >> b;
	string input;
	cin >> input;
	if(input[a-1] == input[b-1])
		cout  << "0" << endl;
	else
		cout << "1" << endl;
	return 0;
}	