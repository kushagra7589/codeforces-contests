#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>

const int M = 1e9+7;
const int MAX_SIZE = 1e5+10;

multiset<int> str; 

int main()
{
	ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	for(int i=0; i < input.length(); i++)
	{
		str.insert(input[i]-97);
	}
	mutilset<int>::iterator start = str.begin();
	start++;
	for(multiset<int>::iterator it = start; it != str.end(); it++)
	{
		mutilset<int>iterator prev = it;
		prev--;
		if(*prev == *it)
			continue;
		else
			
	}
	return 0;
}