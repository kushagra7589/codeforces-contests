#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>

const int MAX_SIZE = 1e5+10;

vector<bool> flag(MAX_SIZE);
set<int> reqd;
string boards;

int main()
{
	ios_base::sync_with_stdio(false);
	int k;
	cin >> k;
	cin >> boards;
	int n = boards.size();
	for(int i=0; i<boards.size(); i++)
		flag[i] = false;
	for(int i=0; i<n; i++)
	{
		if(boards[i] == '1' && flag[i] == false)
		{
			int flag1 = 0;
			for(int j=i+k+1; j<n; j+=k)
			{
				if(boards[j] == '1' && flag[i] == false)
				{
					flag1 = 1;
					reqd.insert(j+1);
					flag[j] = true;
					if(boards[j-k-1] == '1' && flag[j-k-1] == false)
					{
						reqd.insert(j-k);
						flag[j-k-1] = true;
					}
				}
			}
			if(flag1)
			{
				reqd.insert(i+1);
				flag[i] = true;
			}
		}
	}
	// sort(reqd.begin(), reqd.end());
	if(reqd.empty())
		cout << "0 0" << endl;
	else
	{
		for (auto i : reqd)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}