#include <bits/stdc++.h>

using namespace std;

int main() {
	char a, b;
	cin >> a >> b;
	int n;
	cin >> n;
	char cw_dp[4] = {118, 60, 94, 62};
	map<char, int> cw_check = {{118, 0}, {60, 1}, {94, 2}, {62, 3}};
	char ccw_dp[4] = {118, 62, 94, 60};
	map<char, int> ccw_check = {{118, 0}, {60, 3}, {94, 2}, {62, 1}};
	int N = n + cw_check[a];
	int N1 = n + ccw_check[a];
	N %= 4;
	N1 %= 4;
	if(ccw_dp[N1] == b && cw_dp[N] == b) {
		cout << "undefined" << endl;
	}
	else if(cw_dp[N] == b) {
		cout << "cw" << endl;
	}
	else if(ccw_dp[N1] == b) {
		cout << "ccw" << endl;
	}
	else {
		cout << "undefined" << endl;
	}
	return 0;
}