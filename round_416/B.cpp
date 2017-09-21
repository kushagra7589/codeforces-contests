#include <bits/stdc++.h>

using namespace std;

#define fast_io() ios_base::sync_with_stdio(false)

typedef long long ll;

#define mp make_pair
#define pb push_back
#define F first
#define S second

std::vector<int> v;

int main()
{
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	int l, r, x;
	int a = 0;
	while(m--)
	{
		cin >> l >> r >> x;
		a = 0;
		for(int i = l; i <= r; i++)
		{
			if(v[i] < v[x])
				a++;
		}
		if(l + a == x)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}