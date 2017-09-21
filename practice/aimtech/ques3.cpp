#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	int i = 0;
	int n = input.length();
	while(i < n-1 && input[i] == 'a')
	{
		i++;
	}
	if(i == n-1)
	{
		if(input[i] == 'a')
			input[i] = 'z';
		else
			input[i] -= 1;
	}
	else
	{
		while(i < n && input[i] != 'a')
		{
			input[i] -= 1;
			i++;
		}
	}
	cout << input << endl;
	return 0;
}