#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAX_SIZE = 100;

vector<char> letter(MAX_SIZE);

int main()
{
	ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	for(int i=0; i<input.length(); i++)
	{
		letter[i] = input[i];
	}
	bool added = false;
	bool palindrome = true;
	int i = 0, j = input.length()-1;
	while(i < j)
	{
		if(letter[i] == letter[j])
		{
			i++;
			j--;
		}
		else if(added == false)
		{
			added = true;
			for(int k = input.length(); k>=j+2; k--)
			{
				letter[k] = letter[k-1];
			}
			letter[j+1] = letter[i];
			i++;
		}
		else
		{
			palindrome = false;
			break;
		}
	}
	if(palindrome)
	{
		if(added == false)
		{
			for(int k = input.length(); k>=j+2; k--)
			{
				letter[k] = letter[k-1];
			}
			letter[j+1] = letter[i];
		}
		for(int i=0; i<=input.length(); i++)
		{
			cout << letter[i];
		}
		cout << endl;
	}
	else
	{
		cout << "NA" << endl;
	}
	return 0;
}