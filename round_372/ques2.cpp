#include <bits/stdc++.h>

using namespace std;

vector<int> count1(27);

int get_index(char c)
{
	return ((c == '?') ? 26 : c-65);
}

void flush()
{
	for(int i=0; i<27; i++)
	{
		count1[i] = 0;
	}
}

int check(string a)
{
	int completed = 0;
	for(int i=0; i<a.length(); i++)
	{
		int index = get_index(a[i]);
		if(index != 26)
		{
			if(count1[index] == 0)
			{
				count1[index] += 1;
				completed += 1;
			}
			else
			{
				return -1;
			}
		}
		else
		{
			count1[index] += 1;
		}
	}
	return completed;
}

string output;

int main()
{
	ios_base::sync_with_stdio(false);
	string input;
	cin >> input;
	int com = 0;
	int flag = 0;
	int i;
	if(input.length() > 25)
	{
		for(i=0; i<input.length()-25; i++)
		{
			string temp = input.substr(i, 26);
			com = check(temp);
			// cout << input[i] << " " << temp << endl;
			// cout << input[i] << " " << com << endl;
			if(com == -1)
			{
				flush();
				continue;
			}
			else
			{
				if(com + count1[26] == 26)
				{
					int k = 0;
					for(int j=0; j<temp.length(); j++)
					{
						if(temp[j] != '?')
						{
							// cout << temp[j];
							output += temp[j];
						}
						else
						{
							while(k < 26)
							{
								if(count1[k] == 0)
								{
									// cout<< char(k+65);
									output += char(k+65);
									k++;
									break;
								}
								k++;
							}
						}
					}
					flag  = 1;
					// cout << endl;
					break;
				}
				else
				{
					flush();
					continue;
				}

			}
		}
		if(!flag)
		{
			cout << -1 << endl;
		}
		else
		{
			for(int j=0; j < i; j++)
			{
				if(input[j] != '?')
					cout << input[j];
				else
					cout << 'A';
			}
			for(int j=0; j<26; j++)
			{
				cout << output[j];
			}
			for(int j=i+26; j<input.length(); j++)
			{
				if(input[j] != '?')
					cout << input[j];
				else
					cout << 'A';
			}
			cout << endl;
		}
	}
	else
	{
		cout << -1 << endl;
	}
	return 0;
}