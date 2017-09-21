#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 1;
const int M = 1e9+7;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string tim;
	cin >> tim;
	if(n == 12)
	{
		if(tim[3] > '5')
			tim[3] = '5';
		if(tim[0] == '0')
		{
			if(tim[1] == '0')
				tim[1] = '1';
		}
		else if(tim[0] == '1')
		{
			if(tim[1] > '2')
				tim[1] = '2';
		}
		else if(tim[1] != '0')
		{
			tim[0] = '0';
		}
		else
		{
			tim[0] = '1';
		}
	}
	else if(n == 24)
	{
		if(tim[3] > '5')
			tim[3] = '5';
		if(tim[0] == '2')
		{
			if(tim[1] > '3')
				tim[1] = '3';
		}
		else if(tim[0] > '2')
		{
			tim[0] = '0';
		}
	}
	cout << tim << endl;
	return 0;
}