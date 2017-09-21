#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define ll long long
#define vl vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int, int>

const int M = 1e9+7;
const int MAX_SIZE = 1e5+10;

int main()
{
	ios_base::sync_with_stdio(false);
	int a, b;
	cin >> a >> b;
	if(a == 1)
	{
		cout << b << endl;
		for(int i=b; i>0; i--)
		{
			cout << i << " ";
		}
		cout << endl;
		return 0;
	}
	if(b == 1)
	{
		cout << a << endl;
		for(int i=1; i<=a; i++)
		{
			cout << i << " ";
		}
		cout << endl;
		return 0;
	}
	if(a >= b)
	{
		cout << a + b << endl;
		for(int i=1; i<=a; i++)
		{
			cout << 2*i - 1 << " "; 
		}
		for(int i=1; i<=b; i++)
		{
			cout << 2*i << " ";
		}
		cout << endl;
	}
	else
	{
		cout << a + b << endl;
		for(int i=2*b; i>0; i-=2)
		{
			cout << i - 1 << " "; 
		}
		for(int i=2*a; i>0; i-=2)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}