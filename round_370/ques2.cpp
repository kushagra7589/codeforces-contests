#include <bits/stdc++.h>

using namespace std;
int _R, _L, _U, _D; 

int main()
{
	ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	_R = _L = _U = _D = 0;	
	if(input.length()&1)
		cout <<  -1 << endl;
	else
	{
		for(int i=0; i<input.length(); i++)
		{
			if(input[i] == 'R')
				_R++;
			else if(input[i] == 'U')
				_U++;
			else if(input[i] == 'D')
				_D++;
			else
				_L++;
		}
		// cout << _R << _L << _U << _D << endl;
		int left = (max(_R, _L) - min(_R, _L)) + (max(_U, _D) - min(_U, _D));
		cout << left/2 <<  endl;
	}
	return 0;
}