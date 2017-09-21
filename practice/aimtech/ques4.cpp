#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pb push_back
#define mp make_pair
#define F first
#define S second

// vll make_string;

// bool make_sum(ll a, int i, int n, int max_a)
// {
// 	if(i == n)
// 	{
// 		if(a <= max_a)
// 		{
// 			make_string[i] = a;
// 			return true;
// 		}
// 		else
// 		{
// 			return false;
// 		}
// 	}
// 	else
// 	{
// 		make_string[i] = min(a, max_a);
// 		return make_sum(a - min(a, max_a), i+1, n, make_string[i]);
// 	}
// }

void swap(ll &a, ll &b)
{
	ll temp = a;
	a = b;
	b = temp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	ll zero, both1, both2, ones;
	cin >> zero >> both2 >> both1 >> ones;
	// if(zero == 0 && ones == 0 && both1 == 0 && both2 == 0)
	// {
	// 	cout
	// }
	// if(zero == 0 || ones == 0 || (both2 == 0 && both1 == 0))
	// {
	// 	cout << "Impossible" << endl;
	// 	return 0;
	// }
	// if(both1 == 0 || both2 == 0)
	// {
	// 	swap(both1, both2);
	// }
	swap(both1, both2);
	ll d1 = 1 + 8*zero;
	ll d2 = 1 + 8*ones;
	ll root_d1 = sqrt(d1);
	ll root_d2 = sqrt(d2);
	// cout << "d1 = " << d1 << " d2 = " << d2 << endl;
	if(root_d1*root_d1 != d1 || root_d2*root_d2 != d2)
	{
		cout << "Because not perfect square!" << endl;
		cout << "Impossible" << endl;
		return 0;
	}
	ll n1 = 1 + root_d1;
	ll n2 = 1 + root_d2;
	if(!(n1&1) && !(n2&1))
	{
		n1= n1/2;
		n2= n2/2;
		// cout << "n1 = " << n1 << " n2 = " << n2 << endl;
		// if(n1*n2 == both1*both2)
		// {
		// 	if(n1 + n2 < 1e6)
		// 	{
		// 		for(int i=0; i<n1; i++)
		// 			cout << "0";
		// 		for(int i=0; i<n2; i++)
		// 			cout << "1";
		// 		cout << endl;
		// 	}
		// 	else
		// 	{
		// 		cout << "Because greater than 1e6" << endl;
		// 		cout << "Impossible" << endl;
		// 	}
  // 		}
  // 		else
  // 		{
  // 			cout << "Because equations are not consistent !" << endl;
  // 			cout << "Impossible" << endl;
  // 		}
		ll z = (n1-(both2%n1))*(n2-(both2/n1)) + (both2%n1)*(n2-both2/n1 - 1);
		// cout << "first 1's : " << both2/n1 << endl;
		// cout << "first 0's : " << n1 - both2%n1 << endl;
		// cout << "second 1's : " << 1 << endl;
		// cout << "second 0's : " << both2%n1 << endl;
		// cout << "third 1's : " << n2 - both2/n1 - 1 << endl;
		// cout << z << endl;
		if(z == both1)
		{
			for(int i=0; i<both2/n1; ++i)
			{
				cout << '1';
			}
			for(int i=0; i<n1-(both2%n1); i++)
			{
				cout << '0';
			}
			if(n2 != both2/n1)
				cout << '1';
			for(int i=0; i<(both2%n1); i++)
			{
				cout << '0';
			}
			for(int i=0; i<n2-(both2/n1)-1; i++)
			{
				cout << '1';
			}
			cout << endl;
		}
		else
		{
			cout << "Because equations not consistent !" << endl;
			cout << "Impossible" << endl;
		}
	}
	else
	{
		cout << "Because not an integer ! " << endl;
		cout << "Impossible" << endl;
	} 
	return 0;
}