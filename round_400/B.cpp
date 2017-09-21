#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define F first
#define S second
#define mp make_pair

bool is_prime(int N)
{
	for(int i=2; i<=sqrt(N); i++)
	{
		if(N % i == 0)
			return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	if(n == 1)
	{
		cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	if(n == 2)
	{
		cout << 1 << endl;
		cout << 1 << " ";
		cout << 1 << endl;
		return 0;
	}
	cout << 2 << endl;
	for(int i=2; i<=n+1; i++)
	{
		if(is_prime(i))
			cout << 1 << " ";
		else
			cout << 2 << " ";
	}
	cout << endl;
	return 0;
}