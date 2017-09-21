#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 1e5+10;
const int M = 1e9+7;


set<int> deleted;
multiset<ll> max_sum;
vector<ll> prefix_sum(MAX_SIZE);
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	prefix_sum[0] = 0;
	ll input;
	deleted.insert(0);
	deleted.insert(n+1);
	for(int i=1; i<=n; i++)
	{
		cin >> input;
		prefix_sum[i] = input + prefix_sum[i-1];
	}
	max_sum.insert(prefix_sum[n]);
	for(int i=0; i<n; i++)
	{
		cin >> input;
		deleted.insert(input);
		set<int>::iterator curr = deleted.find(input);
		// cout << "current : " << *curr << endl;
		set<int>::iterator nx = next(curr, 1);
		// cout << "next : " << *nx << endl;
		set<int>::iterator prev = next(curr, -1);
		// cout << "prev : " << *prev << endl;
		// cout << "deleted value : " << prefix_sum[(*nx)-1] - prefix_sum[*prev] << endl;
		ll key = prefix_sum[(*nx)-1] - prefix_sum[*prev];
		if(max_sum.find(key)!=max_sum.end())
		   max_sum.erase(max_sum.equal_range(key).first);
		// cout << "inserted instead : " << prefix_sum[(*nx)-1] - prefix_sum[*curr] << " and  " << prefix_sum[(*curr) - 1] - prefix_sum[*prev] << endl;
		max_sum.insert(prefix_sum[(*nx)-1] - prefix_sum[*curr]);
		max_sum.insert(prefix_sum[(*curr) - 1] - prefix_sum[*prev]);
		multiset<ll>::iterator maxi = max_sum.end();
		maxi--;
		cout << *maxi << endl;
	}
	return 0;
}