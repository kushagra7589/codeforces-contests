#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 50;

vector<pair<int, int > > v(MAX_SIZE);


bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
	if(a.first != b.first) return a.first > b.first;
	if(a.second == 7) return true;
	if(b.second == 7) return false;
	return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	int a[6];
	while(t--)
	{

		for(int i=0; i<MAX_SIZE; i++)
			v[i] = mp(0, i);
		int n;
		cin >> n;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<6; j++)
			{
				cin >> a[j];
				v[a[j]].F += 1;
			}
		}
		sort(v.begin(), v.end(), compare);
		vector<int> ans;
		for(int i=0; i<6; i++)
		{
			ans.pb(v[i].S);
		}
		sort(ans.begin(), ans.end());
		for(auto k : ans)
		{
			cout << k << " ";
		}
		cout << endl;
	}
	return 0;
}