#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 110;

vector< pll > bottles;

struct sort_pred_des {
    bool operator()(const std::pair<int,int> &left, const std::pair<int,int> &right) {
        return left.second > right.second;
    }
};

void swap(pll &a, pll &b)
{
	pll temp = a;
	a = b;
	b = temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll total_amt = 0;
	bottles.resize(n+1);
	for(int i=0; i<n; i++)
	{
		cin >> bottles[i].F;
		total_amt += bottles[i].F;
	}
	for(int i=0; i<n; i++)
	{
		cin >> bottles[i].S;
	}
	sort(bottles.begin(), bottles.end(), sort_pred_des());
	ll cumulative_cap = 0;
	int k = 0;
	for(auto i : bottles)
	{
		cumulative_cap += i.S;
		k++;
		if(cumulative_cap >= total_amt)
			break;
	}
	cumulative_cap = 0;
	sort(bottles.begin(), bottles.end());
	for(int i=0; i<k; i++)
		cumulative_cap += bottles[i].S;
	int current  = k;
	int start = k-1;
	while(cumulative_cap < total_amt)
	{	
		start = k-1;
		while(start >= 0 && bottles[start].S > bottles[current].S)
		{
			start--;
		}
		if(start != -1)
		{
			swap(bottles[start], bottles[current]);
			cumulative_cap += bottles[start].S - bottles[current].S;
		}
		current++;
	}
	ll amt = 0;
	for(int i=0; i<k; i++)
	{
		cout << bottles[i].F << " ";
		amt += bottles[i].F;
	}
	cout << endl;
	ll tim = total_amt - amt;
	cout << k << " " << tim << endl;
	return 0;
}