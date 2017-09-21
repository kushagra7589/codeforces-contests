#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fast_io() ios_base::sync_with_stdio(false);

vector<int> arr;
vector<int> A;

int main()
{
	fast_io();
	int n, k;
	cin >> n >> k;
	arr.resize(n);
	A.resize(k);
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for(int i = 0; i < k; i++)
	{
		cin >> A[i];
	}
	if(k == 1)
	{
		for(int i = 0; i < n; i++)
		{
			if(arr[i] == 0)
			{
				arr[i] = A[0];
			}
		}
		vector<int> C = arr;
		sort(arr.begin(), arr.end());
		for(int i = 0; i < n; i++)
		{
			if(C[i] != arr[i])
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
		cout << "No" << endl;
		return 0;
	}
	set<int> number;
	for(int i = 0; i < k; i++)
	{
		number.insert(A[i]);
	}
	if(number.size() > 1)
	{
		cout << "Yes" << endl;
	}
	else
	{
		for(int i = 0; i < n; i++)
		{
			if(arr[i] == 0)
			{
				arr[i] = A[0];
			}
		}
		vector<int> C = arr;
		sort(arr.begin(), arr.end());
		for(int i = 0; i < n; i++)
		{
			if(C[i] != arr[i])
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
		cout << "No" << endl;
		return 0;
	}
	return 0;
}