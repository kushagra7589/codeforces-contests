#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define F first 
#define S second

bool check(int x, int k, int B, int &a, int &b, int &m)
{
	a = b = -1;
	for(int i=1; i<k; i++)
	{
		if((B - (i*x)) % (k - i) == 0)
		{
			a = (B - (i*x))/(k - i);
			b = x - a;
			m = i;
			if(a >= 0 && b >= 0)
				return true; 
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n, k, G, B;
	cin >> n >> k >> G >> B;
	char g, bl;
	if(G <= B)
	{
		g = 'B';
		bl = 'G';
	}
	else
	{
		g = 'G';
		bl = 'B';
	}
	G = max(G, B);
	B = n - G;
	int x = ceil(G/k);
	int a, b, m;
	if(k == 1)
	{
		if(G - B > 1)
			cout << "NO" << endl;
		else
		{
			for(int i=0; i<B; i++)
				cout << g << bl;
			for(int i=0; i<G-B; i++)
				cout << g;
		}
	}
	else if(check(x, k, B, a, b, m) == true)
	{
		for(int i=0; i<a; i++)
		{
			for(int j=0; j<k; j++)
				cout << g;
			for(int j=0; j<k; j++)
				cout << bl;
		}
		for(int i=0; i<b; i++)
		{
			for(int j=0; j<k; j++)
				cout << g;
			for(int j=0; j<m; j++)
				cout << bl;
		}
		for(int i=0; i<(G%k); i++)
			cout << g;
	}
	else if(check(x+1, k, B, a, b, m) == true)
	{
		for(int i=0; i<a; i++)
		{
			for(int j=0; j<k; j++)
				cout << g;
			for(int j=0; j<k; j++)
				cout << bl;
		}
		for(int i=0; i<b-1; i++)
		{
			for(int j=0; j<k; j++)
				cout << g;
			for(int j=0; j<m; j++)
				cout << bl;
		}
		for(int i=0; i<(G%k); i++)
			cout << g;
		for(int i =0; i<m; i++)
			cout << bl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}