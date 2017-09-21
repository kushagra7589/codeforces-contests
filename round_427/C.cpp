#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAX_SIZE = 1e5 + 10;

#define F first
#define S second

ll dp[12][110][110];
vector<ll> A[12][110][110];
set< pair<int, int> > points;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < 12; i++) {
		for(int j = 0; j < 110; j++) {
			for(int k = 0; k < 110; k++) {
				dp[i][j][k] = 0;
			}
		}
	}
	int n, q, c;
	cin >> n >> q >> c;
	int s, x, y;
	for(int i = 0 ;  i < n; i++) {
		cin >> x >> y >> s;
		A[0][x][y].push_back(s);
		points.insert({x, y});
	}
	for(int j = 0; j < c + 1; j++) 
	{
		for(auto &p : points) {
			if(j > 0)
			{
				for(int x = 0; x < A[j - 1][p.F][p.S].size(); x++)
				{
					A[j][p.F][p.S].push_back((A[j - 1][p.F][p.S][x] + 1) % (c + 1));
				}
			}
			ll SUM = 0;
			for(int x = 0; x < A[j][p.F][p.S].size(); x++)
			{
				SUM += A[j][p.F][p.S][x];
			}
			dp[j][p.F][p.S] = SUM;
		}
	}
	// for(int i = 0; i < 6; i++)
	// {
	// 	for(int j = 0; j < 6; j++) 
	// 	{
	// 		cout << dp[1][i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	for(int k = 0; k < c + 1; k++) {
		for(int i = 1; i <= 100; i++) {
			for(int j = 1; j <= 100; j++)
			{
				dp[k][i][j] += (dp[k][i - 1][j] + dp[k][i][j - 1]) - dp[k][i - 1][j - 1];
			}
		}	
	}
	// for(int i = 0; i < 6; i++)
	// {
	// 	for(int j = 0; j < 6; j++) 
	// 	{
	// 		cout << dp[2][i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	ll t, x1, x2, y1, y2;
	while(q--) {
		cin >> t >> x1 >> y1 >> x2 >>  y2;
		t = t % (c + 1);
		x1 -= 1;
		y1 -= 1;
		// cout << "t = " << t << endl;;
		ll ans = dp[t][x2][y2] - dp[t][x2][y1] - dp[t][x1][y2] + dp[t][x1][y1];
		cout << ans << endl;
	}
	return 0;
}