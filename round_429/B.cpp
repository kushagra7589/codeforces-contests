#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll arr[(int)1e6 + 10];
int main() {
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n ;
	bool odd = false;
	ll sum = 0;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		if(arr[i] % 2 == 1) {
			odd = true;
		}	
		sum += arr[i];
	}
	if(sum % 2 == 0) {
		if(odd) {
			cout << "First" << endl;
		}
		else {
			cout << "Second" << endl;
		}
	}
	else {
		cout << "First" << endl;
	}
	return 0;
}