#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

ll A[N];
pair<ll, int> B[N];
ll C[N];
int main() {
	ios_base::sync_with_stdio(false);
	int m;
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> A[i];
	}
	ll x;
	for(int i = 0; i < m; i++) {
		cin >> x;
		B[i] = {x, i};
	}
	sort(A, A + m, greater<ll>());
	sort(B, B  + m);
	for(int i = 0 ; i < m; i++) {
		C[B[i].second] = A[i];
	}
	for(int i = 0; i < m; i++) {
		cout << C[i] << " ";
	}
	cout << endl;
	return 0;
}