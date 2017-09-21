#include <bits/stdc++.h>

using namespace std;

const int MAX_SIZE = 1e5+10;

bool marked[MAX_SIZE] = {0};
int present[MAX_SIZE] = {0};


int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int x;
	for(int i=0; i<n; i++)
	{
		cin >> x;
		present[x] += 1;
	}
	int max_count1 = 0;
	int count1 = 0;
	if(n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	for(int i=2; i<MAX_SIZE; i++)
	{
		count1 = 0;
		if(marked[i] == false)
		{
			for(int a=i; a<MAX_SIZE; a+=i)
			{
				marked[a] = true;
				count1 += present[a];
			}
		}
		max_count1 = max(count1,  max_count1);
	}
	cout << max(max_count1, 1) << endl;
	return 0;
}