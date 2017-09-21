#include <bits/stdc++.h>

using namespace std;
const long double PI = 3.14159265358979;
typedef long double ld;

ld distance(ld x1, ld y1, ld x2, ld y2)
{
	ld dis = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	return dis;
}

ld area(ld a, ld b, ld c)
{
	ld s = (a + b + c)/2;
	ld ans  = sqrt(s*(s-a)*(s-b)*(s-c));
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	ld gx, gy, gr, wx, wy, wr;
	for(int k=1; k<=t; k++)
	{
		cin >> gx >> gy >> gr >> wx >> wy >> wr;
		ld c = distance(gx, gy, wx, wy);
		ld x = (c*c + gr*gr - wr*wr)/(2*c);
		ld y = (c*c - gr*gr + wr*wr)/(2*c);
		ld z = sqrt((gr*gr) - (x*x));
		// cout << z << endl;
		ld a1 = area(gr, gr, 2*z);
		// cout << a1 << endl;
		ld a2 = area(wr, wr, 2*z);
		ld ans;
		if(gr + wr > c && fabs(gr - wr)  < c)
		{
			// cout << "1: " << endl;
			ans = PI*(gr*gr) - (acos(x/gr)*gr*gr) - (acos(y/wr)*wr*wr) + a2 + a1;
		}
		else if(gr + wr <= c)
		{
			// cout << "2 : " << endl;
			ans = PI*(gr*gr);
		}
		else
		{
			// cout 	<< "3 : " << endl;
			ans = max((ld)0, PI*(gr*gr - wr*wr));
		}
		// cout << "Case #" << k << ": " << ans << endl;
		printf("Case #%d: %.10Lf\n", k, ans);
	}
	return 0;
}