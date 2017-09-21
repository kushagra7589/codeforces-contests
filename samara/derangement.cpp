#include <bits/stdc++.h>

using namespace std;
const int MAX_SIZE  = 200000 + 10;
int arr[MAX_SIZE][2];
vector <int> fixed1;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	// int count = 0;
	for(int i=1; i<=n; ++i) {
		cin >> arr[i][0];
		if(arr[i][0] == i) {
			arr[i][1] = 1;
			fixed1.push_back(i);
		}
		else {
			arr[i][1] = 0;
		}
	}
	int num_of_swaps = (fixed1.size() + 1)/2;
	cout << num_of_swaps << endl;
	if(num_of_swaps > 0) {
		for(int i=0; i<fixed1.size()-1; i+=2) {
			cout << fixed1[i] << " " << fixed1[i + 1] << endl;
		}
		int last;
		if(fixed1.size() % 2 == 1) {
			if(fixed1.size() == 1 && fixed1[fixed1.size()-1] != 2) {
				last = 2;
			}
			else {
				last = 1;
			}
			cout << fixed1[fixed1.size() - 1] << " " << last << endl; 
		}
	}
	return 0;
}