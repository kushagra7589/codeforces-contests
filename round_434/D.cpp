#include <bits/stdc++.h>

using namespace std;

#define pb push_back
struct cmp {
    bool operator() (const string& a, const string& b) const {
        if(a.length() == b.length())
			return a < b;
		else
			return a.length() < b.length();
    }
};

map<string, int> freq;

map<string, set<string, cmp> > sub;

string A[(int)1e5];

int main()
{
	int n;
	cin >> n;
	string num;
	for(int i = 0; i < n; i++)
	{
		cin >> num;
		A[i] = num;
		sub[num] = set<string, cmp>();
		for(int k = 1; k < 10; k++)
		{
			for(int j = 0; j < 10 - k; j++)
			{
				string s = num.substr(j, k);
				if(freq.find(s) == freq.end())
				{
					freq[s] = 0;
				}
				if(sub[num].find(s) == sub[num].end())
					freq[s] += 1;
				sub[num].insert(s);
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		// cout << A[i] << " -> ";
		for(auto &j : sub[A[i]])
		{
			// cout << j << " | " << freq[j] << endl; 
			if(freq[j] == 1)
			{
				cout << j << endl;
				break;
			}
		}
		// cout << endl;
	}
	return 0;
}