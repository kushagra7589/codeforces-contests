#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	string ch;
	cin >> ch;
	if((ch[0] != 'a' && ch[0] != 'h') && (ch[1] != '1' && ch[1] != '8'))
		cout << 8 << endl;
	else if((ch[0] == 'a' || ch[0] == 'h') && (ch[1] == '1' || ch[1] == '8'))
		cout << 3 << endl;
	else if((ch[0] == 'a' || ch[0] == 'h') && (ch[1] != '1' && ch[1] != '8'))
		cout << 5 << endl;
	else if((ch[0] != 'a' && ch[0] != 'h') && (ch[1] == '1' || ch[1] == '8'))
		cout << 5 << endl;
	return 0;
}