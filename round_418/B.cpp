#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fast_io() ios_base::sync_with_stdio(false);

vector<int> A;
vector<int> B;

int main()
{
	fast_io();
	int n;
	cin >> n;
	A.resize(n);
	B.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> B[i];
	}
	set<int> diff;
	int sum = 0;
	int sum1 = 0;
	set<int> done;
	for(int i = 0; i < n; i++)
	{
		if(A[i] != B[i])
		{
			diff.insert(i);
		}
		else
		{
			done.insert(A[i]);
			sum += A[i];
		}
		sum1 += A[i];
	}
	set<int> missing;
	for(int i = 1; i <= n; i++)
	{
		if(done.find(i) == done.end())
		{
			missing.insert(i);
		}
	}
	ll K = (n * (n + 1)) / 2;
	vector<int> C = A;
	if(diff.size() == 1)
	{
		auto u = *diff.begin();
		C[u] = K - sum;
	}
	else
	{
		auto u = *diff.begin();
		auto v = *(++diff.begin());
		auto one = *missing.begin();
		auto two = *(++missing.begin());
		if(one == A[u] || two == A[u])
		{
			C[u] = A[u];
			C[v] = B[v];
		}
		else if(one == B[u] || two == B[u])
		{
			C[u] = B[u];
			C[v] = A[v];
		}
		else if(one == A[v] || two == A[v])
		{
			C[u] = B[u];
			C[v] = A[v];
		}
		else
		{
			C[u] = A[u];
			C[v] = A[v];
		}
	}
	for(auto &i: C)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}