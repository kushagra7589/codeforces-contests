#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define F first
#define S second

const int MAX_SIZE = 1e3+10;

int a[MAX_SIZE];
int b[MAX_SIZE];
int c[MAX_SIZE];
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int flag = 0;
	for(int i= 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		c[i] = a[i];
		if(a[i] != b[i])
			flag = 1;
	}
	if(!flag)
	{
		sort(a, a + n, greater<int>());
		for(int i = 0; i < n; i++)
		{
			if(c[i] != a[i])
			{
				flag = 1;
				break;
			}
		}
		if(flag)
		{
			cout << "unrated" << endl;
		}
		else
		{
			cout << "maybe" << endl;
		}
	}
	else
	{
		cout << "rated" << endl;
	}
	return 0;
}