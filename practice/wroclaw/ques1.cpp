#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define vll vector< ll >
#define F first
#define S second

const int M = 1e9+7;
const int MAX_SIZE = 751;
// vector< pair< ll, int > > input;
priority_queue< pair< ll, int>, vector< pair< ll , int > >, greater< pair< ll, int > > > pq;
vll input[MAX_SIZE];

void clear()
{
	while(!pq.empty())
	{
		pq.pop();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	while(cin >> n)
	{
		for(int i=0; i<n; i++)
		{
			input[i].resize(n);
			for(int j=0; j<n; j++)
			{
				cin >> input[i][j];
			}
			sort(input[i].begin(), input[i].end());
		}
		ll sum = 0;
		for(int i=0; i<n; i++)
		{	
			sum += input[i][0];
			pq.push(mp(input[i][1] - input[i][0], i));
		}
		int prev = -1;
		int index = 0;
		queue< ll > q1;
		q1.push(sum);
		for(int i=0; i<n-1; i++)
		{
			pair<ll, int> p = pq.top();
			pq.pop();
			pair<ll, int> q = pq.top();
			// cout << p.F << ":" << 
			if(p.S == prev)
			{
				if(p.F == q.F)
				{
					sum = 0;
					clear();
					for(int j=0; j<n; j++)
					{
						sum += input[j][0];
						if(j != q.S)
						{
							pq.push(mp(input[j][1] - input[j][0], j));
						}
					}
					sum += q.F;
					prev = q.S;
					index = 1;
					pq.push(mp(input[q.S][index+1] - input[q.S][index], q.S));
					// cout << sum << " ";
					q1.push(sum);
				}
				else
				{
					index += 1;
					pq.push(mp(input[p.S][index+1] - input[p.S][index], p.S));
					sum += p.F;
					// cout << sum << " ";
					prev = p.S;
					q1.push(sum);
				}
			}
			else
			{
				sum = 0;
				clear();
				for(int j=0; j<n; j++)
				{
					sum += input[j][0];
					if(j != p.S)
					{
						pq.push(mp(input[j][1] - input[j][0], j));
					}
				}
				sum += p.F;
				prev = p.S;
				index = 1;
				pq.push(mp(input[p.S][index+1] - input[p.S][index], p.S));
				// cout << sum << " ";
				q1.push(sum);
			}
		}
		while(!q1.empty())
		{
			ll ans = q1.front();
			q1.pop();
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}