#include <bits/stdc++.h>

using namespace std;

set<string> check;

int main()
{
	int n, m;
	cin >> n >> m;
	int prod = n*m;
	int maxim = prod - min(n, m);
	string input;
	int cnt = 0;
	bool flag = false;
	bool start_F = false;
	bool end_F = false;
	int start_rect, end_rect;
	bool ans = true;
	for(int i = 0; i<n; i++)
	{
		cin >> input;
		input += ".";
		for(int j=0; j<input.length(); j++)
		{
			if(start_F == false)
			{
				if(input[j] == 'X')
					start_F = true;
			}
			else if(end_F == false)
			{
				if(input[j] == '.')
					end_F = true;
			}
			else if(end_F == true)
			{
				if(input[j] == 'X')
				{
					ans  = false;
					break;
				}
			}
		}
		if(start_F == true)
		{
			check.insert(input);
		}
		start_F = false;
		end_F = false;
	}

	if(ans)
	{
		if(check.size() == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	else
		cout << "NO" << endl;
}