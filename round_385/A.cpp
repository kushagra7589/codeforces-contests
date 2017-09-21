#include <bits/stdc++.h>

using namespace std;

set<string> arr;

int main()
{
	string input;
	cin >> input;
	int n = input.length();
	int cnt = 0;
	for(int i=0; i<n; i++)
	{
		string temp = input;
		input = input[n-1] + input;
		input.erase(n);
		// cout << input << endl;
		int flag  = 0;
		for(auto it : arr)
		{
			if(input == it)
			{
				flag = 1;
				break;
			}
		}
		arr.insert(input);
		if(!flag)
			cnt += 1;
	}
	cout << cnt << endl;
	return 0;
}