#include <bits/stdc++.h>

using namespace std;


#define ll long long

const int MAX_SIZE = 410;

vector< vector<int> > grid(MAX_SIZE, vector<int> (MAX_SIZE));
vector< int > row(MAX_SIZE);
vector< int > col(MAX_SIZE);

int arr[MAX_SIZE][MAX_SIZE];
int count1 = 0;
ll dp(int x, int y, int n)
{
	cout << "X = " << x << " Y = " << y << endl;
	count1++;
	if(x >= n)
		return 0;
	if(y < 0)
		return 0;
	if(arr[x][y] != -1)
		return arr[x][y];
	if(grid[x][y] * row[x] * col[y] == 1)
	{
		cout << "It is one !" << endl;
		// if(arr[x][y] == -1)
		arr[x][y] = dp(x, y-1, n) + dp(x+1, y, n);
		return arr[x][y] ;
	}
	else
	{
		cout << "It is zero ! " << endl;
		row[x] = row[x]*-1;
		col[y] = col[y]*-1;
		// if(arr[x][y] == -1)
		arr[x][y] = 1 + dp(x, y-1, n) + dp(x+1, y, n);
		return arr[x][y];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int n, m;
	while(t--)
	{
		count1 = 0;
		for(int i=0; i<MAX_SIZE; i++)
		{
			for(int j=0; j<MAX_SIZE; j++)
			{
				arr[i][j] = -1;
			}
		}
		for(int i=0; i<MAX_SIZE; i++)
		{
			row[i] = 1;
			col[i] = 1;
		}
		cin >> m >> n;
		string str;
		for(int i=0; i<m; i++)
		{
			cin >> str;
			for(int j=0; j<n; j++)
			{
				if(str[j] == '1')
					grid[i][j] = 1;
				else
					grid[i][j] = -1;
			}
		}
		ll ans = dp(0, n-1, m);
		cout << ans << endl;
		// cout << count1 << endl;
	}
}