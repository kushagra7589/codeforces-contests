#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<ll> V;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll num;
	for(int i=0; i<n; i++) {
		cin >> num;
		V.push_back(num);
	}
	int total = V.size();
	sort(V.begin(), V.end());
	ll diff = V[1] - V[0];
	ll summ = V[1] + V[0];
	ll large = V[n-1];
	ll small = V[0];
	ll ans = summ - 1;
	if(abs(large - ans) < small) {
		cout << "YES" << endl;
		cout << ans << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}