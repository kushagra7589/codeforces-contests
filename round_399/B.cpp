#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;
typedef long double ld;
vector<int> bin;
vector< ll > indices;
int main()
{
	ll n, l, r;
	cin >> n >> l >> r;
	if(n == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	while(n > 0)
	{
		bin.pb(n%2);
		n = n/2;
	}
	ll index = 2;
	for(int i=bin.size()-2; i>=0; i--)
	{
		if(bin[i] == 0)
			indices.pb(index);
		index *= 2;
	}
	ll sum = 0;
	for(auto &i : indices)
	{
		sum += floor(((ld)r + i)/(2*(ld)i)) - ceil(((ld)l + i)/(2*(ld)i)) + 1;
	}
	cout << (r - l + 1) - sum << endl;
	return 0;
}