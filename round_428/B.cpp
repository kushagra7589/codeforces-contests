#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
#define F first
#define S second
#define pll pair<ll, ll>
#define fast_io() ios_base::sync_with_stdio(false);

map<int, int> remaining = {{1, 2}, {2, 2}, {3, 4}, {4, 4}, {5, 6}, {6, 7}, {7, 8}, {0, 0}};

int arr[110];

int main() {
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < k; i++) {
		cin >> arr[i];
	}
	n *= 8;
	int easy;
	int tough;
	int nxt = 8;
	sort(arr, arr + k);
	for(int i = 0; i < k; i++) {
		if(arr[i] >= nxt)
		{
			arr[i] -= nxt;
			n -= nxt;
			easy = arr[i]/8;
			tough = arr[i] % 8;
			n -= (easy * 8);
			if(i == k - 1) {
				n -= tough;
			}
			else if(nxt <= 4) {
				n -= (min(4, tough + 1));
				nxt = 8 - min(4, tough + 1);
			}
			else {	
				n -= remaining[tough];
				nxt = 8 - remaining[tough];
			}
		}
		else {
			// n -= remaining[arr[i]];
			// nxt -= remaining[arr[i]];
			if(i == k - 1) {
				n -= arr[i];
			}
			else if(nxt <= 4) {
				n -= (min(4, arr[i] + 1));
				nxt -= min(4, arr[i] + 1);
			}
			else {	
				n -= remaining[arr[i]];
				nxt -= remaining[arr[i]];
			}
			if(nxt == 0)
				nxt = 8;
		}
		// cout << nxt << endl;
		// cout << i << " " << easy * 8 << " " << remaining[tough] << endl;
		if(n < 0) {
			cout << "NO" << endl;
			return 0;
		} 
	}
	cout << "YES" << endl;
	return 0;
}