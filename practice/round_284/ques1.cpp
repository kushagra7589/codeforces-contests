#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE  = 60;
typedef long long ll;

vector <pair<int, int> > v;
int x = 0;
int main()
{
	ios_base::sync_with_stdio(false);
	int n; int x;
	cin >> n >> x;
	int l, r;
	for(int i=1; i<=n; i++)
	{
		cin >> l >> r;
		v.push_back(make_pair(l, r));
	}
	int a = 1;
	int d = x;
	int term = 0;
	int start, end, tim = 0;
	for(int i=0; i<v.size(); ++i)
	{
		term = floor(((v[i].first - a)/(double)d));
		start = a + (term)*d;
		end = v[i].second;
		tim += end - start + 1;
		// cout << "a = " << a << " start = " << start << " end = " <<  end << endl;
		a = end + 1;
	}
	cout << tim << endl;
	return 0;
}
