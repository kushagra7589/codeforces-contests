#include <bits/stdc++.h>

using namespace std;

int freq[128];

int main()
{
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	for(int i=0; i<128; i++)
		freq[i] = 0;
	for(int i=0; i<s.length(); i++)
	{
		freq[(int)s[i]] += 1;
	}
	int mini = 1e9;
	string comp = "Bulbasr";
	for(auto it : comp)
	{
		if(it == 'u' || it == 'a')
			mini = min(mini, freq[(int)it]/2);
		else
			mini = min(mini, freq[(int)it]);
	}
	cout << mini << endl;
	return 0;
}