#include <bits/stdc++.h>

using namespace std;

map<char, char> keyboard;

int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	for(int i = 0; i < 26; i++)
	{
		keyboard[a[i]] = b[i];
	}
	bool upper = false;
	for(int i = 0; i < c.length(); i++)
	{
		upper = false;
		if(c[i] >= 65 && c[i] <= 90)
			upper = true;
		char x = tolower(c[i]);
		if(keyboard.find(x) == keyboard.end())
		{
			cout << x;
		}
		else
		{
			if(upper)
				cout << (char)toupper(keyboard[x]);
			else
				cout << keyboard[x];
		}
	}
}