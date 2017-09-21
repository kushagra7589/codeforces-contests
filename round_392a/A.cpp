#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pll pair<ll,ll>

int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m, k, x, y;
	cin >> n >> m >> k >> x  >> y;
	ll max_cnt = 1;
	ll min_cnt = 1;
	ll cntx = 0;
	if(n <= 2)
	{
		max_cnt = ceil((ld)k / (n*m));
		min_cnt = k / (n*m);
		cntx += k / (n*m);
		k = k % (n*m);
		if(k > 0)
		{
			ll rows_complete = k/m;
			ll curr_row = rows_complete + min((ll)1, k%m);
			if(curr_row > x)
			{
				cntx += 1;
			}
			else if(curr_row == x)
			{
				ll cols_complete = (k % m) == 0 ? m : k % m;
				if(cols_complete >= y)
					cntx++;
			}
		}
	}
	else
	{
		k = k - (n*m);
		if(k > 0)
		{
			max_cnt += ceil((ld)k / ((n-1) * m));
			min_cnt += k / (2 * (n-1) * m);
			cntx += 1;
			if(x != 1 && x != n)
			{
				cntx += ((k)/(2 * (n-1) * m)) * 2;
			}
			else
			{
				cntx += k/(2 * (n-1) * m);
			}
			// cout << cntx << endl;
			k = k % (2 * (n-1) * m);
			// cout << cntx << endl;
			if(k > 0)
			{
				// cout << "k =  " << k << endl;
				ll rows_complete = k/m;
				ll curr_row = (n-1) - rows_complete ;
				// cout << "curr row : " << curr_row << endl;
				if(curr_row < 1)
				{
					cntx += 1;
					curr_row = abs(curr_row - 2);
					// cout << "curr row : " << curr_row << endl;
					if(x != 1 && curr_row > x)
					{
						cntx += 1;
					}
					else if(curr_row == x)
					{
						ll cols_complete = (k % m) == 0 ? m : k % m;
						if(cols_complete >= y)
							cntx++;
					}
				}
				else
				{
					if(x != n && curr_row < x)
					{
						cntx += 1;
					}
					else if(curr_row == x)
					{
						ll cols_complete = (k % m) == 0 ? m : k % m;
						if(cols_complete >= y)
							cntx++;
					}
				}
			}
		}
		else if(k < 0)
		{
			ll pos = (x-1)*m + y;
			k += n * m;
			// cout << "pos = " <<  
			if(k >= pos)
			{
				cntx += 1;
			}
			min_cnt = 0;
		}
		else if(k == 0)
		{
			cntx = 1;
		}
	}
	cout << max_cnt << " " << min_cnt << " " << cntx << endl;
	return 0;
}