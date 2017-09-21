#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fast_io() ios_base::sync_with_stdio(false);

map<char, vector<int> > indices;
int ans[1501][27];

int getMatched(int left, int right, vector<int> const &A)
{
	// for(auto &i: A)
	// 	cout << i << " ";
	// cout << endl;
	// cout << "l = " << left << " r = " << right;
	if(A.size() == 0)
		return 0;
	int start = lower_bound(A.begin(), A.end(), left) - A.begin();
	// if(A[start] != A.size() && A[start] > right)
	// 	return 0;
	// if(A[start] == A.size())
	// 	return 0;
	// if(A[start - 1] == left)
	// cout << " Start = " << start;
	int add = (A[start] >= left) ? 1 : 0;
	int fin = upper_bound(A.begin(), A.end(), right) - A.begin() - 1;
	// if(fin ==  || A[fin] < left)
	// 	return 0;
	// cout << " finish = " << fin << endl;
	// cout << "matched  = " << fin - start + add << endl;; 
	return max(0, fin - start + add);
}

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
	for(int i = 0; i < n; i++)
	{
		if(indices.find(color[i]) == indices.end())
		{
			indices[color[i]] = vector<int>();
		}
		indices[color[i]].pb(i);
	}
	int q;
	cin >> q;
	while(q--)
	{
		int a;
		char c;
		cin >> a >> c;
		if(ans[a][c - 'a'] == -1)
		{
			int l = 0;
			int h = n + 1;
			int mid;
			while(l < h)
			{
				// cout << l << " " << h << endl;
				int mid = (l + h)/2;
				bool flag = false;
				// cout << "L = " << l << " H = "<< h << " MID = " << mid << endl;
				for(int i = 0; i <= n - mid; i++)
				{
					int x = i, y = i + mid - 1;
					int gm = getMatched(x, y, indices[c]);
					// cout << "l = " << i << " h = " << y << " matched = " << gm << " mid = " << mid << endl;
					if(a + gm >= mid)
					{
						flag = true;
						break;
					}
				}
				if(flag)
					l = mid + 1;
				else
					h = mid;
			}
			// rem[mp(a, c)] = l - 1;
			ans[a][c - 'a'] = l - 1;
			cout << ans[a][c - 'a'] << endl;
		}
		else
		{
			cout << ans[a][c - 'a'] << endl;
		}
	}
	return 0;
}