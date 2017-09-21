#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second

int find(vector<int> &C, int x) { return (C[x] == x) ? x : C[x] = find(C, C[x]); }
void merge(vector<int> &C, int x, int y) { C[find(C, x)] = find(C, y); }

set<int> representatives;
vector<int> C;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int x;
	C.resize(n+1);
	for(int i=1; i<=n; i++)
		C[i] = i;
	for(int i=1; i<=n; i++)
	{
		cin >> x;
		merge(C, i, x);
	}
	for(int i=1; i<=n; i++)
	{
		representatives.insert(find(C, C[i]));
	}
	cout << representatives.size() << endl;
	return 0;
}