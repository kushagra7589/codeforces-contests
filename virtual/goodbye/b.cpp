#include <bits/stdc++.h>
using namespace std;

int main(){
	long long a, b, x, ans = 0;
	cin >> a >> b;
	for(int i = 2; i <= 60; i++){
		for(int j = 1; j < i; j++){
			x = 1;
			for(int k = 1; k < i; k++){
				x <<= 1;
				if(k != j)
					x++;
			}
			if(a <= x && x <= b)
				ans++;
		}
		// cout << x 
	}
	cout << ans << endl;
	return 0;
}