#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define pll pair<ll>
#define mp make_pair
#define F first
#define S second

string input;
const int MAX_SIZE = 2e5+10;

bool del[MAX_SIZE];

bool delete_next_R(int k, int n)
{
	cout << "Current : " << k << endl;
	int i = (k+1);
	while(input[i] == 'D' && i < input.length())
		i = (i+1);
	cout << "Deleted " << i << endl;
	if(i == input.length())
		return true;
	else
	{
		input += 'D';
		return false;
	}
}

bool delete_next_D(int k, int n)
{
	cout << "Current : " << k << endl;
	int i = (k+1);
	while(input[i] == 'R' && i < input.length())
		i = (i+1);
	cout << "Deleted " << i << endl;
	if(i == input.length())
		return true;
	else
	{
		input += 'R';
		return false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	cin >> input;
	memset(del, false, sizeof(del));
	int i = 0;
	bool res = false;
	char ans;
	while(true)
	{
		
		if(input[i] == 'D')
		{
			res = delete_next_R(i, n);
			if(res == true)
			{
				ans = 'D';
				break;
			}
		}
		else if(input[i] == 'R')
		{
			res = delete_next_D(i, n);
			if(res == true)
			{
				ans = 'R';
				break;
			}
		}
		i = (i+1);
	}
	cout << ans << endl;
	return 0;
}