#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll freq[10] = {0};

int main() {
	ll k;
	string n;
	cin >> k >> n;
	for(int i = 0; i < n.length(); i++) {
		ll a = n[i] - 48;
		freq[a] += 1;
	}
	ll sum = 0;
	for(ll i = 0; i < 10; i++) {
		sum += freq[i] * i;
	}
	int cnt = 0;
	while(sum < k) {
		int i = 0;
		while(freq[i] == 0) i++;
		sum += 9 - i;
		freq[i]--;
		cnt++;
	}
	cout << cnt << endl;
	return 0;	
}