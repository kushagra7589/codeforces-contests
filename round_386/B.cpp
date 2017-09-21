#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first 
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	string inp;
	cin >> n;
	cin >> inp;
	string ans = "";
	for(auto i : inp)
	{
		if(n % 2)
		{
			ans += i;
		}
		else
		{
			ans = i + ans;
		}
		n--;
	}
	cout << ans << endl;
	return 0;
}