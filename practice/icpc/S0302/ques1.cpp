#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>

const int MAX_SIZE = 1e5+10;

vll blue;
vll red;

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string input;
	for(int i=0; i<n; i++)
	{
		cin >> input;
		string num = input.substr(0, input.length()-1);
		if(input[input.length()-1] == 'B')
			blue.push_back(stoi(num));
		else
			red.push_back(stoi(num));
	}
	sort(blue.begin(), blue.end(), std::greater<int>());
	sort(red.begin(), red.end(), std::greater<int>());
	int size = min(red.size(), blue.size());
	ll sum = 0;
	for(int i=0; i<size; i++)
	{
		sum += red[i] + blue[i];
	}
	sum = sum - (2*size);
	cout << sum << endl;
	return 0;
}