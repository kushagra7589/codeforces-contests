#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define mp make_pair
#define pb push_back
#define F first 
#define S second

map<char, int> freq;

void fill(string &S, char fil, int reqd)
{
	int filled = 0;
	for(auto &it : S)
	{
		if(filled == reqd)
			break;
		if(it == '?')
		{
			it = fil;
			filled += 1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	freq['A'] = 0;
	freq['C'] = 0;
	freq['G'] = 0;
	freq['T'] = 0;
	int n; 
	cin >> n;
	string dna;
	cin >> dna;
	if(n % 4 == 0)
	{
		for(auto it : dna)
		{
			if(it != '?')
				freq[it] += 1;
		}
		int reqd = n /4;
		for(auto &it : freq)
		{
			if(it.S > reqd)
			{
				cout << "===" << endl;
				return 0;
			}
			else
			{
				it.S = reqd - it.S;
			}
		}
		fill(dna, 'A', freq['A']);
		fill(dna, 'C', freq['C']);
		fill(dna, 'G', freq['G']);
		fill(dna, 'T', freq['T']);
		cout << dna << endl; 
	}
	else
	{
		cout << "===" << endl;
	}
	return 0;
}