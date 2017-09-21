#include <bits/stdc++.h>

using namespace std;
ex
typedef long long ll;
const int MAX_SIZE = 1<<19;

int number[MAX_SIZE] = {0};
ll pow2[18];

int get_index(ll n)
{
	int index = 0;
	int i = 0;
	while(n > 0)
	{
		index += pow2[i]*(n%2);
		n = n/10;
		i++;
	}
	return index;
}

int get_index(string pattern)
{
	int index = 0;
	int i = 0;
	for(int j=pattern.length()-1; j>=0; --j)
	{
		if(pattern[j] == '1')
		{
			index += pow2[i];
		}
		i++;
	}
	return index;
}

unordered_map<ll, int> store_index;

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	pow2[0] = 1;
	for(int i=1; i<18; i++)
	{
		pow2[i] = pow2[i-1]*2;
	}
	string choice; ll num;
	string pattern;
	while(t--)
	{
		cin >> choice;
		if(choice == "+")
		{
			cin >> num;
			int i;
			if(store_index.find(num) == store_index.end())
			{
				i = get_index(num);
				store_index[num] = i;

			}
			else
			{
				i = store_index[num];
			}
			number[i] += 1;
		}
		else if(choice == "-")
		{
			cin >> num;
			int i = store_index[num];
			number[i] -= 1;
		}
		else if(choice == "?")
		{
			cin >> pattern;
			pattern = string(18 - pattern.length(), '0').append(pattern);
			cout << number[get_index(pattern)] <<  endl;
		}
	}
	return 0;
}