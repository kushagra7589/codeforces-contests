#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pil pair<int, ll>
#define pli pair<ll, int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int MAX_SIZE = 110;
const int M = 1e9+7;

int arr[MAX_SIZE];
// char input[MAX_SIZE];
int main()
{	
	int n;
	cin >> n; 
	for(int i=1; i<=n; i++)
	{
		cin >> arr[i];
	}
	cin.get();
	set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'y'};
	for(int i=1; i<=n; i++)
	{
		string input;
		getline(cin, input);
		int count = 0;
		for(auto &x : input)
		{
			if(vowels.find(x) !=  vowels.end())
				count++;
		}
		if(count != arr[i])
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}	