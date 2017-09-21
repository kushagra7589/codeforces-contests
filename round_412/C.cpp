#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define mp make_pair
#define pb push_back
#define F first
#define S second

typedef vector<ll> VI;
typedef pair<ll, ll> PII;


/*
 code taken from stanfordacm repo for ICPC cheatsheet 
*/

// return a % b (positive value)
ll mod(ll a, ll b) {
	return ((a%b) + b) % b;
}

// computes gcd(a,b)
ll gcd(ll a, ll b) {
	while (b) { ll t = a%b; a = b; b = t; }
	return a;
}

// computes lcm(a,b)
ll lcm(ll a, ll b) {
	return a / gcd(a, b)*b;
}

// (a^b) mod m via successive squaring
ll powermod(ll a, ll b, ll m)
{
	ll ret = 1;
	while (b)
	{
		if (b & 1) ret = mod(ret*a, m);
		a = mod(a*a, m);
		b >>= 1;
	}
	return ret;
}

// returns g = gcd(a, b); finds x, y such that d = ax + by
ll extended_euclid(ll a, ll b, ll &x, ll &y) {
	ll xx = y = 0;
	ll yy = x = 1;
	while (b) {
		ll q = a / b;
		ll t = b; b = a%b; a = t;
		t = xx; xx = x - q*xx; x = t;
		t = yy; yy = y - q*yy; y = t;
	}
	return a;
}


// computes b such that ab = 1 (mod n), returns -1 on failure
ll mod_inverse(ll a, ll n) {
	ll x, y;
	ll g = extended_euclid(a, n, x, y);
	if (g > 1) return -1;
	return mod(x, n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	ll x, y, p, q;
	while(t--)
	{
		cin >> x >> y >> p >> q;
		// int flag = 0;
		// if(p == q)
		// 	flag = 1;
		// if(!flag)
		// {
		// 	if(p == 0 && x == 0)
		// 		cout << 0 << endl;
		// 	else
		// 	{
		// 		// ll inv = mod_inverse(p, q - p);
		// 		// ll u;
		// 		// // cout << inv << endl;
		// 		// if(inv == -1)
		// 		// 	flag = 1;
		// 		if(!flag)
		// 		{
		// 			// cout << 
		// 			// cout << mod(q*x - p*y, q - p) << endl;
		// 			u = mod(inv * mod(x - y, q - p), q - p);
		// 			cout << "u = " << u << endl;
		// 			ll k = max((ld)0, ceil((((ld)q*x - (ld)p*y)/p - (ld)u)/(q - p)));
		// 			cout << "k = "<< k << endl; 
		// 			u = u + (q-p)*k;
		// 			cout << "u = " << u << endl;
		// 			ll s = (p*u + p*y - q*x)/(q-p);
		// 			cout << "s = " << s << endl;
		// 			cout << s + u << endl;
		// 		}
		// 		else
		// 		{
		// 			cout << -1 << endl;
		// 		}
		// 	}
		// }
		// else
		// {
		// 	cout << -1 << endl;
		// }

		if(p == q)
		{
			if(x == y)
				cout << 0 << endl;
			else
				cout << -1 << endl;
		}
		else if(p == 0 && x == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			ll u = mod((x - y), q - p);
			cout << u <<  endl;
			// ll k = ceil(((double)q * x - (double)p*y - (double)p*u)/((double)p*(q - p)));
			ll den = p*(q - p);
			ll num = q*x - p*y - p*u;
			ll K = (num + den - 1)/den;
			// cout << "num = " << num << " den = " << den << " K = " << K << endl; 
			u = u + K*(q - p);
			ll k = (u + y - x)/(q - p);
			ll s = k*p - x;
			// printf("u = %d, %s\n", );
			// cout << "u = " << u << " k = " << k << " s = " << s << endl;
			cout << s + u << endl;
		}
	}
	return 0;
}