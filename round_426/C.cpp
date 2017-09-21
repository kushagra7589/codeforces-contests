#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

// bool checkCube(ll x) {
// 	if(x == 1) return true;
// 	if (x < 8) return false;
// 	ll l = 1;
// 	ll h = x + 1;
// 	while(l < h) {
// 		ll mid = (l + h) / 2;
// 		if(mid * mid <= x) {
// 			l = mid + 1;
// 		}
// 		else {
// 			h = mid;
// 		}
// 	}
// 	h = l;
// 	l = 1;
// 	while(l < h) {
// 		ll mid = (l + h) / 2;
// 		if(mid * mid * mid <= x) {
// 			l = mid + 1;
// 		}
// 		else {
// 			h = mid;
// 		}
// 	}
// 	l -= 1;
// 	return (l * l * l == x);
// }

set<ll> cubes;

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	for(ll i = 1; i * i * i <= 1e9; i++) {
		cubes.insert(i*i*i);
	}
	while(n--) {
		ll x, y;
		cin >> x >> y;
		ll sum = x + y;
		x = max(x, y);
		ll X = x;
		y = sum - x;
		ll Y = y;
		ll g = gcd(x, y);
		x /= g;
		y /= g;
		// cout << y;
		if(g == 1 && X != 1 && Y != 1) {
			cout << "No" << endl;
			continue;
		}
		ll num = x * x * y;
		ll den = x * y * y;
		if(X % num != 0 || Y % den != 0) {
			cout << "No" << endl;
			continue;
		}
		ll rem1 = X / num;
		ll rem2 = Y / den;
		if(rem1 != rem2)
		{
			cout << "No" << endl;
			continue;
		}
		if(cubes.find(rem1) == cubes.end())
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}