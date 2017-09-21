#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 410;

vector< vector< int > > grid(MAX_SIZE, vector<int>(MAX_SIZE));
vector< int > row(MAX_SIZE);
vector< int > col(MAX_SIZE);
int n, m;

void display()
{
	for(int i=0; i<m; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << max(0, grid[i][j]*row[i]*col[j]);
		}
		cout << endl;
	}
}

int check(int x, int y)
{
	// cout << "[" << x << ", " << y << "] = " ;
	if(x >= m || y < 0)
	{
		// cout << endl;
		return 0;
	}
	if(grid[x][y] * row[x] * col[y] == 1)
	{
		// cout << 1 << endl;
		return 0;
	}
	else
	{
		// cout << 0 << endl;
		row[x] *= -1;
		col[y] *= -1;
		grid[x][y] *= -1;
		return 1;
	}	
}

int shoot(int r, int c)
{
	int ans = 0;
	if(r < m)
	{
		for(int i=n-1; i>max(0, c); i--)
		{
			ans += check(r, i);
			// display();
		}
	}
	if(c >= 0)
	{
		for(int i=0; i<min(n-1, r); i++)
		{
			ans += check(i, c);
			// display();
		}
	}
	ans  += check(r, c);
	// display();
	return ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
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
		int res = 0;
		for(int i=n-1, j=0; i>=0 || j<m; i--, j++)
		{
			res += shoot(j, i);
		}
		cout << res << endl;
	}
}