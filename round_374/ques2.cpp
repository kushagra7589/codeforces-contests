#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

int find(int n, map<int, int> const &a)
{
	int res = 0;
	for(auto j : a)
	{
		if(j.F != n)
		{
			res += j.S;
		}
		else
			break;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	map<int, int> count;
	int n, k;
	cin >> n >> k;
	string pass;
	vector<string> input;
	for(int i=0; i<n; i++)
	{
		cin >> pass;
		input.pb(pass);
	}
	// sort(input.begin(), input.end());
	int i=0;
	while(i < n)
	{
		int len = input[i].length();
		if(count.find(len) == count.end())
			count[len] = 0;
		count[len] += 1;
		i++;
	}
	cin >> pass;
	int index = 0;
	int res = find(pass.length(), count);
	int min_res = res + 1;
	int max_res = res + count[(int)pass.length()];
	min_res = min_res + 5*((min_res-1)/k);
	max_res = max_res + 5*((max_res-1)/k);
	cout << min_res << " " << max_res << endl;
	return 0;
}