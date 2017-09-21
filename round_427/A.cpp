
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

int main() {
	int s, v1, v2, t1, t2;
	cin >> s >> v1 >> v2 >> t1 >> t2;
	int first = 2*t1 + s*v1;
	int second = 2*t2 + s*v2;
	if(first > second) {
		cout << "Second";
	}
	else if(first < second) {
		cout << "First";
	}
	else {
		cout << "Friendship";
	}
	return 0;
}