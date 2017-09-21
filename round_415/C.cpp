#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define F first
#define S second

const int M = 1e9 + 7;

const int N = 3e5 + 10;

vector<ll> power2;
vector<ll> arr(N), arr1;
vector<ll> mul(N);
vector<ll> prefix(N);
int main()
{
	ios_base::sync_with_stdio(false);
	ll a = 0, b = 0;
	power2.resize(N);
	power2[0] = 1;
	prefix[0] = 1;
	for(int i = 1; i < N; i++)
	{
		power2[i] = ((ll)2 * power2[i - 1]) % M;
		prefix[i] = (prefix[i - 1] + power2[i]) % M;
	}
	int n;
	cin >> n;
	arr1.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}
	sort(arr1.begin(), arr1.end());
	for(int i = 1; i < n; i++)
	{
		arr[i] = arr1[i] - arr1[i - 1];
		// cout << arr[i] << " ";
	}
	for(int i = 0; i < n - 1; i++)
	{
		a = (a + power2[i]) % M;
	}
	mul[1] = a;
	mul[n - 1] = a;
	for(int i = 2; i <= n/2; i++)
	{
		mul[i] = (mul[i - 1] + prefix[n - 1 - i] - prefix[i - 1 - 1] + M) % M; 
		mul[n - i] = mul[i];
	}
	ll ans = 0;
	for(int i = 1; i < n; i++)
	{
		ans = (ans + ((arr[i]*mul[i]) % M)) % M; 
	}
	// cout << endl;
	// b = (((a - power2[1] + M) % M) + power2[n - 2]) % M;
	// // cout << a << " " << b << endl;
	// ll ans = 0;
	// if(n > 1)
	// 	ans = (ans + ((arr[1] * a) % M)) % M;
	// if(n - 1 > 1)
	// 	ans = (ans + ((arr[n - 1] * a) % M)) % M;
	// for(int i = 2; i < n - 1; i++)
	// {
	// 	ans = (ans + ((arr[i] * b) % M)) % M;	
	// }	
	cout << ans << endl;
	return 0;
}