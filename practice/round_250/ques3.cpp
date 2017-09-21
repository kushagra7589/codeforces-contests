#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

vector<ll> Count;
vector<ll> Exp10(10);

void makePow()
{
	Exp10[0] = 1;
	for(int i=1; i<=9; i++)
	{
		Exp10[i] = Exp10[i-1]*10;
	}
}
int greater3(int x)
{
	return (x > 3)?1:0;
}

ll give_occurrences(ll n)
{
	ll mult = 1;
	ll ans = 0;
	while(n > 0)
	{
		ans = (n/10 + greater3(n % 10));
		Count.pb(ans);
		n /= 10;
	}
	ans = Count[Count.size()-1]*Exp10[Count.size()-1];
	for(int i=Count.size()-2; i>=0; i--)
	{
		Count[i] = Count[i] - Count[i+1];
		ans += Count[i]*Exp10[i];
	}
	Count.clear();
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	ll n;
	makePow();
	while(t--)
	{
		cin >> n;
		cout << n - give_occurrences(n) << endl;
	}
	return 0;
}