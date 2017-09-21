#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	ll sum = 0;
	ll x;
	ll b;
	ll d;
	ll count = 0;
	cin >> n;
	cin >> b >> d;
	for(int i=0; i<n; i++)
	{
		cin >> x;
		if(x <= b)
		{
			sum += x;
			if(sum > d)
			{
				count++;
				sum = 0;
			}
		}
	}
	cout << count << endl;
	return 0;
}