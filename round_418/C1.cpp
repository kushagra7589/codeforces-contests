#include <bits/stdc++.h>

using namespace std;

int ans[1501][27];

int main()
{
	fast_io();
	for(int i = 0; i < 1501; i++)
	{
		for(int j = 0; j < 27; j++)
		{
			ans[i][j] = -1;
		}
	}
	int n;
	cin >> n;
	string color;
	cin >> color;
	int q;
	int a, c;
	while(q--)
	{
		cin >> a >> c;
		if(ans[a][c - 'a'] == -1)
		{

		}
		cout << ans[a][c - 'a'] << endl;
	}
}