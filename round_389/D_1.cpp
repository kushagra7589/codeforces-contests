#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

map<string, vector<int> > beauty;

int main()
{
	ios_base::sync_with_stdio(false);
	int k, n;
	cin >> k >> n;
	string input;
	int b;
	for(int i=0; i<k; i++)
	{
		cin >> input >> b;
		if(beauty.find(input) == beauty.end())
		{
			vector<int> v;
			beauty[input] = v;
		}
		beauty[input].pb(b);
	}
	for(auto &it : beauty)
	{
		sort(it.S.begin(), it.S.end(), greater<int>());
	}
	// for(auto it : beauty)
	// {
	// 	// cout << it.F << " -> ";
	// 	for(auto j : it.S)
	// 	{
	// 		cout << j << " ";
	// 	}
	// 	cout << endl;
	// }

	int ans  = 0;
	vector< pair<int, int> > max_self;
	map<string, bool> checked;
	for(auto it : beauty)
	{
	    checked[it.F] = false;
	}
	for(auto it : beauty)
	{
	    if(checked[it.F] == false)
	    {
    		string rev = it.F;
    		reverse(rev.begin(), rev.end());
    		if(rev != it.F)
    		{
    // 			cout << "checking string :" << it.F << " and its reverse : " << rev << endl; 
    			int i = 0;
    			if(beauty.find(rev) != beauty.end())
    			{
    				while(i < min(it.S.size(), beauty[rev].size()) && (it.S[i] + beauty[rev][i] > 0))
    				{
    				// 	cout << "adding " << it.S[i] << " from " << it.F << " and " << beauty[rev][i] << " from " << rev << endl;
    					ans += it.S[i] + beauty[rev][i];
    					i++;
    				}
    				// beauty.erase(it.F);
    				// beauty.erase(rev);
    			}
    		}
    		else
    		{
    // 			cout << "checking " << it.F << " with size " << it.S.size() << endl;
    			int i = 0;
    			while((i < it.S.size() - 1) && (it.S[i] + it.S[i+1] > 0) && (it.S[i] + it.S[i+1] > it.S[i]))
    			{
    				ans += it.S[i] + it.S[i+1];
    				i += 2;
    			}
    			if(it.S.size() - i > 1)
    			{
    				if(it.S[i] > 0)
    				{
    				// 	cout << "adding " << it.S[i] << " and " << it.S[i] + it.S[i+1] << " to max_self" << endl;					
    					max_self.pb(mp(it.S[i], max(0, it.S[i] + it.S[i+1])));
    				}
    			}
    			else if(it.S.size() - i == 1)
    			{
    				if(it.S[i] > 0)
    				{
    				// 	cout << "adding " << it.S[i] << " to max_self" << endl;
    					max_self.pb(mp(it.S[i], 0));
    				}
    			}
    // 			beauty.erase(it.F);
    		}
    		checked[it.F] = true;
    		checked[rev] =  true;
	    }
	}
	int total = 0;
	for(auto it : max_self)
	{
// 		cout << it.S << " " << it.F << endl;
		total += it.S;
	}
	int add = 0;
	for(auto it : max_self)
	{
		add = max(add, total - it.S + it.F);
	}
// 	cout << add << endl;
	ans += add;
	cout << ans << endl;
	return 0;
}