#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

vi black;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	string input;
	cin >>n >> input;
	int i=0;
	int count = 0;
	while(i < n)
	{
		while(input[i] == 'W')
			i++;
		count = 0;
		while(input[i] == 'B')
		{
			count++;
			i++;
		}
		if(count != 0)
			black.pb(count);
	}
	cout << black.size() << endl;
	for(int i=0; i<black.size(); i++)
	{
		cout << black[i] << " ";
	} 
	cout << endl;
	return 0;
}