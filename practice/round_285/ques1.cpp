#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX_SIZE = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	int a, b, c, d;
	cin >> a >> b>> c >> d;
	int one  = max((3*a)/10, a - (a/250)*c);
	int two  = max((3*b)/10, b - (b/250)*d);
	if(one > two)
		cout << "Misha";
	else if(one < two)
		cout << "Vasya";
	else
		cout << "Tie";
	cout << endl;
	return 0;
}