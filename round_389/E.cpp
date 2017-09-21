#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pll pair<ll, ll>
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

bool pred(vector<ll> const &A, ll k, ll mid)
{
	cout << "-----------------------------------------" << endl;
	cout << "mid = " << mid << endl;
	int n = A.size();
	int i = n-1;
	ll coll = 0;
	for(i; i>=0; i--)
	{
		ll x = A[i];
		cout << "x : " << x << endl;
		ll temp = (x >= mid) ? 1 : 0;
		ll b = (x+1)/2;
		ll s = x/2;
		bool equal = (s == b);
		while(s >= mid)
		{
			// if(s >= mid)
			// 	temp *= 2;
			// else if(b >= mid)
			// {
			// 	if(b % 2)
			// 		temp += 1;
			// 	else
			// 		temp = temp*2 - 1;
			// }
			temp *= 2;
			s = s/2;
			b = (b+1)/2;
			equal = (s == b);
		}
		if(b >= mid)
		{
			if(!equal)
				temp = temp*2 - temp/2;
		}
		// cout << "contribution : " << temp << endl;
		coll += temp;
		cout << "total : " << coll << endl;
		if(coll >= k)
			return true;
		if(temp == 0)
			break;
	}
	return false;
}

ll bs(vector<ll> const &A, ll k)
{
	ll l = 1;
	ll sum = accumulate(A.begin(), A.end(), (ll)0);
	ll u = 0;
	for(auto it : A)
	{
		u = max(u, it);
	}
	u += 1;
	// cout << sum << endl;
	if(sum < k)
		return -1;
	while(l < u)
	{
		ll mid = (l+u)/2;
		cout << l << " " << u << " " << mid << endl;
		if(pred(A, k, mid))
			l = mid + 1;
		else
			u = mid;
	}
	return l-1;
}

int main()
{
	ios::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	vector<ll> A;
	A.resize(n+1);
	for(int i=0; i<n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	cout << bs(A, k) << endl; 
	return 0;
}