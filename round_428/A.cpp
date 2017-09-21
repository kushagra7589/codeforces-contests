#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define fast_io() ios_base::sync_with_stdio(false);

int main() {
	int n, k;
	cin >> n >> k;
	int a;
	int i;
	int saved = 0;
	ll ans = 0;
	for(i = 1; i <= n; i++) {
		cin >> a;
		saved += a;
		ans = min(saved, 8);
		k -= ans;
		saved -= ans;
		if(k <= 0)
			break;
	}
	if(k > 0)
		cout << -1 << endl;
	else {
		cout << i << endl;
	}
	return 0;
}