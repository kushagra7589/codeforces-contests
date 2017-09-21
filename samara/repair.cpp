#include <bits/stdc++.h>

using namespace std;

bool checker(int a, int b, int x, int y)
{
	if(min(a, b) < min(x, y))
		return false;
	if(max(a, b) < max(x, y))
		return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, x, y, p, q;
	cin >> a >> b >> x >> y >> p >> q ;
	if(checker(a, b, x, y) == false) {
		if(checker(a, b, p, q) == true) {
			if(checker(a-p, q, x, y) || checker(a-p, b-q, x, y) || checker(p, b-q, x, y) || checker(a-q, p, x, y) || checker(a-q, b-p, x, y) || checker(q, b-p, x, y)) {
				cout << "YES" << endl;
			}
			else 
				cout << "NO" << endl;
		}
		else
			cout << "NO" << endl;
	}
	else {
		if(checker(a-x, y, p, q) || checker(a-x, b-y, p, q) || checker(x, b-y, p, q) || checker(a-y, x, p, q) || checker(a-y, b-x, p, q) || checker(y, b-x, p, q)) {
			cout << "YES" << endl;
		}
		else 
			cout << "NO" << endl;
	}
	return 0;
}