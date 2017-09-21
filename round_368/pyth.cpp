#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;
	long long m, k;
	if( n == 1 || n == 2){
		cout << "-1" <<  endl;
	}
	else if(n % 2 == 0) {
		m = ((n*n)/4 - 1);
		k = ((n*n)/4 + 1);
		cout << m << " " << k << endl;
	}
	else {
		m = (((n*n) - 1)/2);
		k = (((n*n) + 1)/2);
		cout << m << " " << k << endl;
	}
	return 0;
}