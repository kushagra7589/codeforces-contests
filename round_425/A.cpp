#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long ll;

#define fast_cin() ios_base::sync_with_stdio(false);

set<char> G, B;

int main()
{
	fast_cin();
	string good;
	cin >> good;
	for(int i = 0; i < 26; i++)
	{
		B.insert(i + 'a');
	}
	for(int i = 0; i < good.length(); i++)
	{
		G.insert(good[i]);
		B.erase(good[i]);
	}	
	string pattern;
	cin >> pattern;
	int n;
	cin >> n;
	string check;
	while(n--)
	{
		cin >> check;
		int i = 0;
		int flag = 1;
		int N = check.length();
		int M = pattern.length();
		if(N - M < -1)
		{
			// cout << 1 << endl;
			cout << "NO" << endl;
			continue;
		}
		while(i < N && pattern[i] != '*')
		{
			if(pattern[i] != '?')
			{
				if(pattern[i] != check[i])
				{
					flag = 0;
					break;
				}
			}
			else
			{
				if(G.find(check[i]) == G.end())
				{
					flag = 0;
					break;
				}
			}
			i++;
		}
		if(i == N && i < M && pattern[i] != '*')
		{
			// cout << 2 << endl;
			cout << "NO" << endl;
			continue;
		}
		if(flag == 0)
		{
			// cout << 3 << endl;
			cout << "NO" << endl;
			continue;
		}
		int j = N - 1;
		int k = M - 1;
		while(j >= 0 && k >= 0 && pattern[k] != '*')
		{
			if(pattern[k] != '?')
			{
				if(pattern[k] != check[j])
				{
					flag = 0;
					break;
				}
			}
			else
			{
				if(G.find(check[j]) == G.end())
				{
					flag = 0;
					break;
				}
			}
			j--;
			k--;
		}
		if(j < 0 && k >= 0 && pattern[k] != '*')
		{
			// cout << 4 << endl;
			cout << "NO" << endl;
			continue;
		}
		if(flag == 0)
		{
			// cout << 5 << endl;
			cout << "NO" << endl;
			continue;
		}
		for(int x = i; x <= j; x++)
		{
			if(B.find(check[x]) == B.end())
			{
				flag = 0;
				break;
			}
		}
		if(flag == 0)
		{
			// cout << 6 << endl;
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}
	return 0;
}