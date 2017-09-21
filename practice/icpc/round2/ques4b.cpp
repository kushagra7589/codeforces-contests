#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 1e5+10;

vll arr(MAX_SIZE);
multiset< pil > jack;
multiset< pli > other;
vector< pli > dis;
vi status(MAX_SIZE);

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	memset(status, 0, MAX_SIZE);
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
		dis.pb(arr[i], i);
	}
	sort(dis.begin(), dis.end());
	for(int i=0; i<dis()/2; i++)
	{
		other.insert(mp(dis[i].F, dis[i].S));
	}
	for(int i=dis.size()/2; i < dis.size(); i++)
	{
		jack.insert(mp(dis[i].S, dis[i].F));
	}
	for(int i=1; i<=n; i++)
	{
		if(status[i] == 0)
	}
	return 0;
}