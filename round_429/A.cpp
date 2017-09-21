#include <bits/stdc++.h>

using namespace std;

int freq[26] = {0};

int main() {
	int n, k;
	cin >> n >> k;
	string a;
	cin >> a;
	for(int i = 0; i < n; i++) {
		freq[a[i] - 'a'] += 1;
	}
	int m = 0;
	for(int i = 0; i < 26; i++) {
		if(freq[i] > k) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}