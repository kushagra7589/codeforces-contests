#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

//source : http://codeforces.com/blog/entry/18051

const int N = 1e5 + 10;  // limit for array size
int n;  // array size
ll t[2 * N];

void build() { 
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) { 
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

ll query(int l, int r) {
  ll res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

vector< pair<int, int> > A;

#define mp make_pair

int dist(int a, int b)
{
	if(a >= b) return a - b;
	return (1e6 - b + 1) + a;
}

int main() {

	cin >> n;
	for (int i = 0; i < n; ++i) t[i + n] = 1;
	build();
	A.resize(n);
	int x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		A[i] = mp(x, i);
	}
	sort(A.begin(), A.end());
	int done = 0;
	ll ans = 0;
	vector<int> ind;
	int k = 0;
	// int start = 0;
	int sz = 0;
	int i = 0;
	while(i < n)
	{
		ind.clear();
		// start = 0;
		sz = 0;

		// cout << A[i].first << " ";
		if(i == 0 || A[i].first != A[i - 1].first)
		{
			int j = i;
			while(j < n && A[i].first == A[j].first)
			{
				ind.push_back(A[j].second);
				// start = (dist(A[j].second, k) < dist(ind[start], k)) ? j - i : start;
				sz++;
				j++;
			}
			i = j;
		}
		// cout << start << " " << k << endl;
		int y = (ind[sz - 1] < k) ? 0 : upper_bound(ind.begin(), ind.end(), k) - ind.begin();
		for(int j = 0; j < sz; j++)
		{
			if(done > ind[y])
			{
				ans += query(done, n) + query(0, ind[y] + 1);
			}
			else
			{
				ans += query(done, ind[y] + 1);
			}
			done = (ind[y] + 1) % n;
			modify(ind[y], 0);
			k = ind[y];
			y = (y + 1) % sz;
		}	
	}
	cout << ans << endl;
	return 0;
}