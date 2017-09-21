#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a, b;
	if(n == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	set<int> reqd;
	for(int i = 1; i < 200; i++)
	{
		reqd.insert(i);
	}
	set<int> del;
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;

		int more;
		int less;
		int k;
		for(int j = 1; j <= 200; j++)
		{
			if(j * b >= a)
			{
				less = j - 1;
				break;
			}
		}
		for(int j = 1; j <= 200; j++)
		{
			if(j * (b - 1) >= a)
			{
				more = j;
				break;
			}
		}
		for(auto &j : reqd)
		{
			if(j <= less)
				del.insert(j);
			else if(j >= more)
				del.insert(j);
		}
		for(auto &j : del)
		{
			reqd.erase(j);
		}
		// cout << more  << " " << less << endl;
		del.clear();
	}
	// for(auto &x : reqd)
	// 	cout << x << " ";
	// cout << endl;
	set<int> ans;
	for(auto &r : reqd)
	{
		ans.insert((n + r - 1)/ r);
	}
	// for(auto &i : ans)
	// 	cout << i << " ";
	// cout << endl;
	if(ans.size() != 1)
	{
		cout << -1 << endl;
	}
	else
	{
		auto x = *ans.begin();
		// cout << "ans = ";;
		cout << x << endl;
	}
	return 0;
}