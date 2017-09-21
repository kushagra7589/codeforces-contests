#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE = 3010;
typedef long long ll;

vector< pair<int, pair<string, string> > > v;

void print_ans(int i)
{
	if(v[i].first == 1)
	{
	 	cout << v[i].second.first;
	}
	else
	{
		cout << v[i].second.second;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string one, two;
	for(int i=0 ; i<m; i++)
	{
		cin >> one >> two;
		if(one.length() <= two.length())
		{
			v.push_back(make_pair(1, make_pair(one, two)));
		}
		else
		{
			v.push_back(make_pair(2, make_pair(one, two)));
		}
	}
	for(int i =0; i<n; i++)
	{
		cin >> one;
		for(int j=0; j<v.size(); ++j)
		{
			if(v[j].second.first == one)
			{
				print_ans(j);
				cout << " ";
			}
		}
	}
	cout << endl;
	return 0;
}