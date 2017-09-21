#include <bits/stdc++.h>
#define RIGHT(x) x<<1|1
#define LEFT(x) x<<1
#define PARENT(x) x>>1
using namespace std;
const int MAX_SIZE = 1e5+10;
const int INF = 1e9+1;
typedef long long ll;

// ll arr[MAX_SIZE];
ll min_arr[MAX_SIZE*4];
ll max_arr[MAX_SIZE*4];

void build_max_tree(int v, int l, int r, int *seg)
{
	if(l == r)
	{
		seg[v] = l;
		return;
	}
	else
	{
		int mid = (l+r)/2;
		build_max_tree(LEFT(v), l, mid, seg);
		build_max_tree(RIGHT(v), mid+1, r, seg);
		seg[v] = (max_arr[seg[LEFT(v)]] > max_arr[seg[RIGHT(v)]]) ? seg[LEFT(v)] : seg[RIGHT(v)];
	}
}

void build_min_tree(int v, int l, int r, int *seg)
{
	if(l == r)
	{
		seg[v] = l;
		return;
	}
	else
	{
		int mid = (l+r)/2;
		build_min_tree(LEFT(v), l, mid, seg);
		build_min_tree(RIGHT(v), mid+1, r, seg);
		seg[v] = (min_arr[seg[LEFT(v)]] < min_arr[seg[RIGHT(v)]]) ? seg[LEFT(v)] : seg[RIGHT(v)];
	}
}

ll querymax(int v, int l, int r, int x, int y, int *seg)
{
	if(y < l || r < x)
		return 0;
	else if(x <= l && r <= y)
		return seg[v];
	else
	{
		int mid = (l+r)/2;
		int first = querymax(LEFT(v), l, mid, x, y, seg);
		int second = querymax(RIGHT(v), mid+1, r, x, y, seg);
		return (max_arr[first] >  max_arr[second]) ? first : second;
	}
}

int querymin(int v, int l, int r, int x, int y, int *seg)
{
	if(y < l || r < x)
		return INF;
	else if(x <= l && r <= y)
		return seg[v];
	else
	{
		int mid = (l+r)/2;
		int first = querymin(LEFT(v), l, mid, x, y, seg);
		int second = querymin(RIGHT(v), mid+1, r, x, y, seg);
		if(first == INF)
			return second;
		else if(second == INF)
			return first;
		return (min_arr[first] <  min_arr[second]) ? first : second;	
	}
}

int next_power(double n)
{
	int x = ceil(log2(n)) + 1;
	return 1<<x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for(int k = 1; k<=t; k++)
	{
		int max_seg[4*MAX_SIZE];
		int min_seg[4*MAX_SIZE];
		int n;
		ll a;
		cin >> n >> a;
		int size_arr = next_power(n);
		for(int i=1; i<=n; i++)
		{
			cin >> min_arr[i];
			max_arr[i] = min_arr[i];
		}
		for(int i=n+1; i<=size_arr; i++)
		{
			min_arr[i] = INF;
			max_arr[i] = 0;
		}
		ll final_ans = 1;
		ll lenMaxSubArr[n+1] = {1};
		build_min_tree(1, 1, n, min_seg);
		build_max_tree(1, 1, n, max_seg);
		lenMaxSubArr[1] = 1;
		int maxIndex = 1, minIndex = 1;
		for(int i = 2; i <= n; i++){
			if( min_arr[i] <= min_arr[maxIndex] && min_arr[i] >= min_arr[minIndex])
			{
				lenMaxSubArr[i] = lenMaxSubArr[i-1] + 1;
			}
			else
			{
				if(min_arr[i] < min_arr[minIndex])
				{
					minIndex = i;
					if(min_arr[minIndex] + a - min_arr[maxIndex] >= 0)
					{
						lenMaxSubArr[i] = 1 + lenMaxSubArr[i-1];
					}
					else
					{
						while(min_arr[maxIndex] - min_arr[minIndex] > a)
						{
							lenMaxSubArr[i] = i - maxIndex;
							maxIndex = querymax(1, 1, n, maxIndex+1, i, max_seg);
							// cout << "MX: " << maxIndex << endl;
						}
					}
				}
				else
				{
					maxIndex = i;
					if(min_arr[minIndex] + a - min_arr[maxIndex] >= 0)
					{
						lenMaxSubArr[i] = 1 + lenMaxSubArr[i-1];
						// cout << "checkkk"<<endl;
					}
					else
					{
						while(min_arr[maxIndex] - min_arr[minIndex] > a)
						{
							lenMaxSubArr[i] = i - minIndex;
							minIndex = querymin(1, 1, n, minIndex+1, i, min_seg);
							// cout << "MiN: " << minIndex << endl;
						}
					}
				}
			}
			// cout <<"lenMaxSubArr  " << i<<"  " << lenMaxSubArr[i] << endl;
			if(lenMaxSubArr[i] > final_ans)
				final_ans = lenMaxSubArr[i];
		}
		cout << "Case #" << k << ": " << final_ans << endl;
	}
	return 0;
}