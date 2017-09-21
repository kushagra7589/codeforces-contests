#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e6 + 10;

int prefix[MAX_SIZE];

int main() {
	memset(prefix, 0, sizeof(prefix));
	int n, k;
	cin >> n >> k;
	string S;
	cin >> S;
	int start = -1;
	int end = -1;
	for(int j = 'A'; j < 'Z'; j++) {
		start = -1;
		end = -1;
		for(int i = 0; i < n; i++) {
			if(S[i] == j && start == -1)
				start = i;
			if(S[i] == j)
				end = i;
		}
		if(start != -1) {
			prefix[start] += 1;
			prefix[end + 1] -= 1;
		}
	}
	for(int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + prefix[i];
		if(prefix[i] > k){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}