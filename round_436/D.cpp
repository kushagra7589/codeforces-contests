#include <bits/stdc++.h>

using namespace std;;

typedef long long ll;

#define pb push_back
#define F first
#define S second

const int MAX_SIZE = 2e5 + 10;

int cnt[MAX_SIZE];
int prefix[MAX_SIZE];

set<int> to_add;

int A[MAX_SIZE];
set<int> indices;

const int N = 2e5;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
  for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value) {  // set value at position p
  for (t[p += n] = value; p > 1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r) {  // sum on interval [l, r)
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}

int main()
{
	// int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		to_add.insert(i);
	}
	int x;
	for(int i = 0; i < n; i++)
	{
		cin >> x;
		A[i] = x;
		cnt[x] += 1;
		if(to_add.find(x) != to_add.end())
			to_add.erase(x);
	}
	int ans = to_add.size();
	set<int> inc;
	map<int, set<int> > ind;
	for(int i = 0; i < n; i++)
	{
		if(cnt[A[i]] > 1)
		{
			t[i + n] = 1;
			inc.insert(A[i]);
			if(ind.find(A[i]) == ind.end())
				ind[A[i]] = set<int>();
			ind[A[i]].insert(i);
		}
	}
	build();
	for(auto &i : inc)
	{
		auto a = distance(to_add.lower_bound(i), to_add.begin()); 
		for(auto &j : ind[i])
		{
			if(query(0, j) >= a)
			{
				modify(j, 0);
				break;
			}
		}
	}
	for(int i = n; i < 2*n; i++)
	{
		if(t[i] == 1)
		{
			auto added = *to_add.begin();
			A[i - n] = added;
			to_add.erase(added);
		}
	}
	cout << ans << endl;
	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	return 0;
}