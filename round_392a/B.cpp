#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define pll pair<ll, ll>

map<char, int> modulus1;

int main()
{
	ios_base::sync_with_stdio(false);
	string Str;
	cin >> Str;
	int n = Str.length();
	for(int i=0; i<n; i+=4)
	{
		if(Str[i] != '!')
		{
			modulus1[Str[i]] = 0;
			break;
		}
	}
	for(int i=1; i<n; i+=4)
	{
		if(Str[i] != '!')
		{
			modulus1[Str[i]] = 1;
			break;
		}
	}
	for(int i=2; i<n; i+=4)
	{
		if(Str[i] != '!')
		{
			modulus1[Str[i]] = 2;
			break;
		}
	}
	for(int i=3; i<n; i+=4)
	{
		if(Str[i] != '!')
		{
			modulus1[Str[i]] = 3;
			break;
		}
	}
	int sum = 0;
	for(int i=modulus1['R']; i<n; i+=4)
	{
		if(Str[i] == '!')
			sum += 1;
	}
	cout << sum << " ";
	sum = 0;
	for(int i=modulus1['B']; i<n; i+=4)
	{
		if(Str[i] == '!')
			sum += 1;
	}
	cout << sum << " ";
	sum = 0;
	for(int i=modulus1['Y']; i<n; i+=4)
	{
		if(Str[i] == '!')
			sum += 1;
	}
	cout << sum << " ";
	sum = 0;
	for(int i=modulus1['G']; i<n; i+=4)
	{
		if(Str[i] == '!')
			sum += 1;
	}
	cout << sum << " ";
	return 0;
}